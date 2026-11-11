#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,k,ans=0;
    long long n,d;
    cin>>c>>k;
    while(k--){
        long long arr[200001];
        cin>>n>>d;
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        for(long long i=0;i<n-3;i++){
            if(arr[i+2]-arr[i]<=d&&arr[i+3]-arr[i+2]<=d&&arr[i+1]-arr[i]<=d&&arr[i+3]-arr[i+1]<=d&&arr[i+3]-arr[i]>d){
                ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
