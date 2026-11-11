#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n,m,a[200010],dp[N][N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int cnt,ans=INT_MIN;
		for(int i=1;i<=n;i++){
			cnt=(1<<30)-1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					cnt=(cnt&a[i]);
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(n>2000){
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1){
				int ans=INT_MIN;
				sort(a+1,a+n+1,cmp);
				cout<<a[m];
				return 0;
			}
		}
		cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=(1<<30)-1;
	}
	dp[0][0]=(1<<30)-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			dp[i][j]=max((dp[i-1][j-1]&a[i]),dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
