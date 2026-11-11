#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
char b[N];
string st="",st2="",op;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,duan;
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i]>>b[i];
		if(i == 1){
			duan = a[i];
		}
		else{
		duan = __gcd(duan,a[i]);
		}
	}
	for(int i =1;i<=n;i++){
		op = b[i];
		int j = a[i]/duan;
		while(j){
			if(j&1){
				st += op;
				st2 = op + st2;
			}
			op += op;
			j >>= 1;
		}
	}
//	cout<<st.size() <<' '<<st2.size() + 1;
	long long dp[st2.size() + 1][st2.size() + 1];
	memset(dp,0,sizeof dp);
	for(int i = 1;i<=st.size();i++){
		for(int j =1;j<=st2.size();j++){
			if(st[i] == st2[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
//			cout<<dp[i][j]<<endl;
		}
	}
	cout<<(st.size()-dp[st.size()][st.size()])*duan;
	return 0;
}
