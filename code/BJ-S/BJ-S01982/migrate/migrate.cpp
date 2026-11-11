#include <bits/stdc++.h>
using namespace std;
const int N=2e6+9;
typedef long long ll;
ll c,t,n,d;
ll a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            ll sum=0;
            cin>>n>>d;

            for(int i=1;i<=n;i++){
                cin>>a[i];
            }

            for(int i=1;i<=n;i++){
                int l=i,r=n,mid,ans;
                while(l<=r){
                    mid=(l+r)/2;
                    if(a[mid]-a[i]<=d){
                        ans=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }l=ans-1,r=n;
                int x;
                while(l<=r){
                    mid=(l+r)/2;
                    if(a[mid]-a[ans-1]<=d){
                        x=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }
                l=ans-2,r=n;
                int y;
                while(l<=r){
                    mid=(l+r)/2;
                    if(a[mid]-a[ans-2]<=d){
                        y=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }//cout<<"i:"<<i<<"   ans:"<<ans<<"  x:"<<x<<"   y:"<<y<<"\n";
                x=max(x,ans);
                y=max(y,ans);
                sum+=max(0,x-y);

            }

            /*
            for(int i=1;i+2<=n;i++){
                if(a[i+2]-a[i]<=d)ans++;
            }
            for(int i=1;i+3<=n;i++){
                if(a[i+2]-a[i]<=d&&a[i+3]-a[i]>d){
                    for(int j=i+3;j<=n;j++){
                        if(a[j]-a[i+1]<=d)ans++;
                    }
                }
            }

            for(int i=n;i-3>=1;i--){
                if(a[i]-a[i-2]<=d&&a[i]-a[i-3]>d){
                    for(int j=i-4;j>=1;j--){
                        if(a[i-1]-a[j]<=d)ans++;
                    }
                }
            }*/
            cout<<sum<<"\n";

        }
    }else if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }if(n<=3){
                cout<<"0\n";
                continue;
            }
            
        }
    }

return 0;
}
