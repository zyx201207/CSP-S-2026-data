#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long pre[500005];
long long ans[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=a[i]-a[i-1];
    int tot=0,i=2;
    while(tot<=m){
        tot+=pre[i];
        if(tot>m)break;
        i++;
    }
    ans[1]=i-2;
    int y=2,d=i;
    for(int j=i;j<=n;j++){
        tot=tot+pre[j];
        d++;
        if(tot>m){
            while(tot>m){
                tot-=pre[i-d+1];
                d--;
            }
        }
        else ans[y++]=d;
    }
    long long maxx=-1000000000001;
    for(int i=1;i<=y;i++){
        maxx=max(maxx,ans[i]);
    }
    if(maxx==-1000000000001)cout<<1;
    else cout<<maxx+1;
}
