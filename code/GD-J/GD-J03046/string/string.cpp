#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
//int dp[1005][1005];
int main(){
	//string s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	long long cha=0;
	//long long cha2=0;
	for(int i=1,j=n;i<=(n+1)/2&&j>=(n+1)/2;i++,j--){
		//for(int j=n;j>=(n+1)/2;j--){
			
		if(cha<0){
			long long t=abs(cha);
			int u=i-1;
			ans+=min(t,a[i]);
			//c[i]='1';
			i++;
		}
		else if(cha>0){
			long long t=abs(cha);
			int u=j+1;
			ans+=min(cha,a[j]);
			//c[j]='1';
			j--;
		}
		//else{
		//	i++;
		//	j--;
		//}
		if(c[i]!=c[j]) {
			ans+=min(a[i],a[j]);
		}
		
		cha=a[i]-a[j];
			
			
		//}
	}
	//ans+=cha;
	cout<<ans;
	/*
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	string ss;
	ss=s;
	
	ss='0'+ss;
	reverse(s.begin(),s.end());
	s='0'+s;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	dp[0][1]=0;
	dp[1][0]=0;
	for(int i=1;i<s.size();i++){
		for(int j=1;j<ss.size();j++){
			if(s[i]==ss[j]){
				dp[i][j]=dp[i-1][j-1];
			}
			else dp[i][j]=min(dp[i][j],dp[i-1][j]+dp[i][j-1]);
		}
	}
	cout<<dp[s.size()-1][s.size()-1];
	*/
	return 0;
}
