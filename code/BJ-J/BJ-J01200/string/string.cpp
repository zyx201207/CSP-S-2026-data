#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len,ans,cnt[2];
char tmp;
struct node{
    int l,r;
    char c;
}a[3][200010];
void add(int op,int l,int r,char c){
    a[op][++cnt[op]]={(op?(len-r+1):l),(op?(len-l+1):r),c};
}
signed main(){
    freopen("string.in","r",stdin),freopen("string.out","w",stdout),
    cin.tie(0)->sync_with_stdio(0),cin>>n;
    for(int i=1,x;i<=n;i++)
        cin>>x>>tmp,a[2][i]={len+1,len+=x,tmp};
    for(int i=1,x;i<=n;i++)
        if(a[2][i].r*2<=len)
            add(0,a[2][i].l,a[2][i].r-(a[2][i].r==len/2+1&&(len&1)),a[2][i].c);
        else if(a[2][i].l*2<=len)
            add(0,a[2][i].l,len/2,a[2][i].c),
            add(1,(len+3)/2,a[2][i].r,a[2][i].c);
        else if(a[2][i].r!=len/2+1&&(len&1)||!(len&1))
            add(1,a[2][i].l+(a[2][i].l==len/2+1&&(len&1)),a[2][i].r,a[2][i].c);
    reverse(a[1]+1,a[1]+cnt[1]+1);
    for(int i=1,j=1;i<=cnt[0];i++){
        while(a[1][j].l<=a[0][i].r&&j<=cnt[1])
            ans+=(a[0][i].c!=a[1][j].c)*(min(a[0][i].r,a[1][j].r)-max(a[0][i].l,a[1][j].l)+1),j++;
        j--;
    }
    cout<<ans;
    return 0;
}