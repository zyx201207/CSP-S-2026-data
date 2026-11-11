#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n;
int a;
char c;
string x,y;
long long len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(int j=0;j<a;j++){
			x+=c;
		} 
	}
	long long len2=0;
	if(len%2==1){
		len2=len/2+1;
	}else{
		len2=len/2;
	}
	for(int i=x.size()-1;i>=len2-1;i--){
		y+=x[i];
	}
	x=' '+x;
	y=' '+y;
	int dp[len2+7][len2+7];
	for(int i=1;i<=len2;i++){
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(int i=1;i<=len2;i++){
		for(int j=1;j<=len2;j++){
			if(x[i]==y[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int res=0;
	for(int i=1;i<=len2;i++){
		for(int j=1;j<=len2;j++){
			res=max(res,dp[i][j]);
		}
	}
	cout<<len2-res;
	return 0;
}
