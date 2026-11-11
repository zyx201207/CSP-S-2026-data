#include<bits/stdc++.h>
using namespace std;
int a[20000][0];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdin);
    int c,t;
    cin>>c>>t;
    if(c==1)||(c==12)){
        while(t--){
            int n;
            long long d;
            cin>>n>>d;
            if(n==1){
                cout<<0;
            for(int i=1;i<=n;i++)cin>>a[i];
            long long dis=a[2]-a[1];
            if(dis>d)cout<<0;
            d=d/dis;
            if(d<2){
                cout<<0;
                coutime;
            }
            long long ans=0;
            ans=n-(d*2-1);
            cout<<ans;
        }
        if((c==1)||(c==14)){
            int a,d;
            for(int i=1;i<=n;i++)if(a[i]-b<=a[1]||a[i+d>=a[n])mid=i;
            ans++1-i;
        }
        cout<<mid;
        cout<<ans;
    }
    return 0;
}