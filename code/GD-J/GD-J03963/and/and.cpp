#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,m,ans,b[MAXN],cn[5],dp[MAXN];
bool h;
struct T{
	long long w;
	int u;
}a[MAXN];
int check(int f){
	int cnt=0;
	while(f!=0){
		if(f%2==1)cnt++;
		f/=2;
	}
	return cnt;
}
bool cmp(T a,T b){
	if(a.u==b.u)return a.w>b.w;
	return a.u>b.u;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m; 
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		if(x>4)h=1;
		b[i]=x;
		a[i].w=x;
		a[i].u=check(x);
	}
	sort(b+1,b+n+1);
	if(m==1){
		cout << b[n];
		return 0;
	}
	else if(m==n){
		ans=b[1];
		for(int i=1;i<=n;i++){
			ans=ans&b[i];
		}
		cout << ans;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,b[i]&b[j]);
			}
		}
		cout << ans;
		return 0;
	}
	else if(m==n-1){
		ans=b[2];
		for(int i=2;i<=n;i++){
			ans=ans&b[i];
		}
		cout << ans;
		return 0;
	}
	else if(!h){
		for(int i=1;i<=n;i++){
			cn[b[i]]++;
		}
		if(cn[4]>=m)cout <<4;
		else if(cn[3]>=m) cout << 3;
		else if(cn[2]>=m) cout << 2;
		else if(cn[1]>=m) cout << 1;
		else cout << 0;
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		dp[1]=a[1].w;
		for(int i=2;i<=n;i++){
			for(int j=m;j>=1;j--){
				dp[j]=max(dp[j],dp[j-1]&a[i].w);
			}
		}
		cout << dp[m];
	}
} 
