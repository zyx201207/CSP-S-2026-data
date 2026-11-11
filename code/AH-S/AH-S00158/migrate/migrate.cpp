#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n;
        long long d,ans=0,a,b;
        cin>>n>>d;
        cin>>a>>b;
        long long k=b-a;
        for(int i=3;i<=n;i++)cin>>a;
        if(k>d){
            cout<<"0\n";
            continue;
        }
        long long cnt=d/k;
        cnt=cnt*2;
        if(cnt>n){
            cout<<"0\n";
            continue;
        }
        ans=n-cnt+1;
        cout<<ans<<"\n";
    }
return 0;
}
