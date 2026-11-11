#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[500005],dp[500005],b[500005];


int main(){
	freopen("crystal3.in","r",stdin); 
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long biao = m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		dp[i] = 1;
		b[i] = a[i];
	} 
    sort(b + 1,b + n + 1);
    sort(a + 1,a + n + 1);
    long long ans = 1;
    for(int i = n - 1,i_back = i;i >= 1;i--){
    	if(biao - (b[i + 1 ] - b[i]) >= 0){
    		dp[i] += dp[i + 1];
    		biao = biao - (b[i + 1] - b[i]);
    		b[i] = b[i + 1];
    		ans = max(ans,dp[i]);
		}else{
			biao = m;
			int i2 = i;
			i = i_back;
			i_back--;
		//	cout<<i_back<<endl;
			for(;i2 <= i;i2++){
				b[i2] = a[i2];
				dp[i2] = 1;
			}
		}
	}
	cout<<ans;
    return 0;
}
