#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll a[2100000];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
     int n,d;
     ll ans=0;
     cin>>n>>d;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }

     for(int i=1;i<=n;i++){
          queue <int> q;
           // cout<<q.empty()<<" emp"<<endl;
            int f=0;
        for(int j=i+1;j<=n;j++){
            if(a[j-1]+d<a[j]){
                break;
            }
            if(q.empty()||a[i]+d>=a[j]){
                q.push(j);
              //  cout<<j<<" pppp"<<endl;
            }else{
                while(!q.empty()&&a[q.front()]+d<a[j]){
                    q.pop();
                }
              //  cout<<i<<" "<<q.size()<<" //  "<<a[j]<<" "<<f<<endl;
                if(f&&q.size()>=2){
                    break;
                }
                if(q.size()==2){
                    f=1;
                }

            if(a[i]+d>=a[j]){
                //    cout<<j<<" pppp"<<endl;
                q.push(j);
            }
            }
            if(f){
            //    cout<<i<<" ///////////// "<<j<<endl;
                ans++;
            }
        }
     }
     cout<<ans<<endl;
    }
    return 0;
}

