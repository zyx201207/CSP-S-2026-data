#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e5+5;
ll n,m,a[N],s[N],sum[N],ans,l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i<=n; i++){
		s[i] = a[n]-a[i];
	}
	for(int i = n; i>=1; i--){
		sum[i] = sum[i+1]+s[i];
	}
	for(int i = 1; i<=n; i++){
		while(l<=i && ((sum[l]-sum[i+1])-(i-l+1)*s[i])>m){
			l++;
		}
		ans = max(i-l+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}
