#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int cnt;
    char c;
}a[200005];
int n,m,ct,ans;
int b[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>c[i];
    }
    ct=b[1];
    for(int i=2;i<=n+1;i++){
        if(c[i]==c[i-1]){
            ct+=b[i];
        }else{
            a[++m].cnt=ct;
            a[m].c=c[i-1];
            ct=b[i];
        }
    }
    int l=1,r=m;
    while(l<r){
        int x=min(a[l].cnt,a[r].cnt);
        if(a[l].c!=a[r].c){
            ans+=x;
        }
        a[l].cnt-=x;
        a[r].cnt-=x;
        if(a[l].cnt==0){
            l++;
        }
        if(a[r].cnt==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
