#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,ans,a[MAXN],dp[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	cin>>a[1]>>a[2];
	long long k=abs(a[1]-a[2]),kk=abs(a[1]-a[2]);
	bool v=false;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(abs(a[i]-a[i-1])!=k) v=true;
	}
	if(!v){
		for(int j=1;j<=n;j++){
			if(m-k>=0){
				ans++;
				m-=k;
			}
			else{
				cout<<ans+1;
				return 0;
			}
			k+=kk;
		}
		cout<<ans+1;
		return 0;
	}
	for(int i=a[1];i<=a[n];i++){
		int b[MAXN];
		for(int j=1;j<=n;j++){
			b[j]=i-a[j];
		}
		sort(b+1,b+n+1);
		long long cnt=0,sum=0;
		for(int j=1;j<=n;j++){
			if(b[j]>=0){
				cnt+=b[j];
				if(cnt<=m){
					sum++;
					ans=max(ans,sum);
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
