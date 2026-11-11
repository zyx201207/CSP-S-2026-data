#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
const int N = 5e5+5;
LL n,m,a[N],sum[N];
int l,r,Ans;
LL read(){
    LL su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}
bool check(int cnt){
    for(int i=cnt;i<=n;i++){
        LL res=sum[i]-sum[i-cnt];
        if(a[i]*cnt-res<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    l=1,r=n,Ans=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))Ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<Ans<<"\n";
    return 0;
}
//rp++
//我们会穿过流言喧哗 用力开放对吗 ——《风之子》
