#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	if(s[n]+m>=a[n]*n){
		cout<<n;
		return 0;
	}
	int maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i]-s[j-1]+m>=a[i]*(i-j+1)){
				maxx=max(maxx,i-j+1);
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
}