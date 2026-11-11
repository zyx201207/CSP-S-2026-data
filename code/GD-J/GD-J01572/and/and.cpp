#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 2e5;
ll a[N],n,m,dp[N],ans=0;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
        dp[i]=a[i];
    }for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
        	dp[j]=max(dp[j],dp[j-1]&a[i]);
    	}
	}cout<<dp[m];
    return 0;
}
