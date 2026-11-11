#include <bits/stdc++.h>
long long RP=LONG_LONG_MAX;
using namespace std;

int n,m,arr[200010];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(m==n){
        int sum;
        sum=arr[1];
        for(int i=2;i<=n;i++){
            sum&=arr[i];
        }
        cout <<sum;
        return 0;
    }
    else if(m==1){
        int ans=-1e9;
        for(int i=1;i<=n;i++){
            ans=max(ans,arr[i]);
        }
        cout <<ans;
        return 0;
    }
    else if(m==2){
        int sum=0,ans=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=arr[i];
                sum&=arr[j];
                ans=max(sum,ans);
            }
        }
        cout <<ans;
        return 0;
    }
    cout <<0;
}
