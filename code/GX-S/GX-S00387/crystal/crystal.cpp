#include<bits/stdc++.h>
using namespace std;
long long a[500009];
int main(){
    freopen("crystal1.in","r",stdin);
    freopen("crystal1.out","w",stdout);
    int n,m,ans=0,t=0,o,x;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i) t=1;
        else t=0;
    }
    x=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(a[i+1]-a[i]==x&&a[i]-a[i-1]!=1)
            t=2;
    }
    sort(a+0,a+n+0);
    if(t==1){
        o=a[n/2]+1;
        int i=0;
        while(o-(o-i)<=m&&o-i!=0){
            m-=o-(o-i);
            ans++;
            i++;
        }
    }
    if(t==2){
        o=a[n/2]+1;
        int i=0;
        while(o-(o-i)<=m&&o-i!=0){
            m-=o-(o-i);
            ans++;
            i+=x;
        }
    }
    cout<<ans;
    return 0;
}
