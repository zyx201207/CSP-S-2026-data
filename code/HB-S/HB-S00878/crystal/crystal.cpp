#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500010],ans=0,cnt=0,jb=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1]) ans++;
        cnt=ans;
        jb=max(cnt,ans);
    }
    jb=jb+2;
    cout<<jb;
    return 0;
}













