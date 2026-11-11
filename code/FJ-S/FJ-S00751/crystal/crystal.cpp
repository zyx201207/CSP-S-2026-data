#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,m,a[maxn],s[maxn],c[maxn];
int main(){
	#define int long long
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		if(i*a[i]-a[i]<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
