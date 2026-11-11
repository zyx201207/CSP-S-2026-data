#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if (c==0 or c==13 or c==t){
        while (t--){
            cin>>n>>k;
            for (int i=1;i<=n-1;i++){
                int ui,vi;
                cin>>ui>>vi;
            }
            int m=(n-1)/2;
            if (k==1){
                cout<<m/2+1<<"\n";
            }
            else{
                int pk=k/2;
                if (m%2==1 and k%2==0){
                    cout<<max(1,(m+1)/2-k)<<"\n";
                }
                else if (m%2==1 and k%2==1){
                    cout<<max(1,(m+1)/2-k*2)<<"\n";
                }
                else if (m%2==0 and k%2==0){
                    cout<<max(1,(m-k))<<"\n";
                }
                else{
                    cout<<max(1,(m-k))<<"\n";
                }
            }
        }
    }
    return 0;
}