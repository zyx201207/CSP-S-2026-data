#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int a[200005];
int p[18];
int n,m; 
int aa=0;
int dp[25][25];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n>>m;
	int mx=0,mxx=0;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	/*if(n<=20){
		int an=a[1];
		for(int i=1;i<=n;i++){
			an=an&a[i];
			dp[i][i]=an;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]&a[i]);
			}
		}
		cout<<dp[n][m];
		return 0;
	}*/
	
	p[0]=1;
	bool ok=false;
	for(int i=1;i<=18;i++){
		p[i]=p[i-1]*2;
		if(n==p[i]){
			ok=true;
		}
	}
	if(ok){
		cout<<((n-1)&(n-2));
		return 0;
	}
	
	
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		int an=a[1];
		for(int i=1;i<=n;i++){
			an=an&a[i];
			if(a[i]!=mx){
				mxx=max(mxx,a[i]);
			}	
		}
		cout<<an;
		return 0;
	}
	if(m==2){
		int xx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				xx=max(xx,a[i]&a[j]);
			}
		}
		cout<<xx;
		return 0;
	}
	
	cout<<mxx;
	
	return 0;
}
