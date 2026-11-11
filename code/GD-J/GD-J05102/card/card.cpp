#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int dp[500010];
int s[300010];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ss=0,x=0;
	for(int i=1;i<=n;i++){
		b[i-x]=a[n-i+1];
		dp[i-x]=dp[i-x-1]*10+b[i-x];
		for(int j=1;j<=i-x;j++){
			if(b[i-j-x]==b[i-x]){
				x+=j;
				i--;
				break;
			}
		}
		ss=dp[i-x];
		while(ss!=0){
			s[ss%10]++;
			ss=ss/10;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
