#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
long long c ,t, n,a[N],d,b[N],bb[N];
int main(){
    freopen("migrate.in","r",stdin);                                          
    freopen("migrate.out","w",stdout); 
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        long long ans = 0;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            b[i] = 0;
        }
        for(int i = 1;i<=n;i++){
            if(a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-3]>d&&i>=4){
                b[i] = 1,bb[i-3] = 2;
                ans++;
            }
            if(b[i-1] == 1&& a[i]-a[i-1]<d&&a[i+1]-a[i-1]>d&&i>=5){
                b[i] = 1,bb[i-4] = 2;
                ans++;
            }
        }
        for(int i = n;i>=1;i--){
            //if(b[i] == 1) continue;
            if(b[i+1] == 1 && a[i+1]-a[i]<d&&a[i+1]-a[i-1]>d&&i+4<=n&&bb[i+1]==2){
                bb[i] = 2;
                ans++;
            }
        }
        cout<<ans<<endl;
        /*for(int i = 1;i<=n;i++){
		    cout<<b[i]<<" ";	
		}
		cout<<endl;*/
    }
    return 0;
}
