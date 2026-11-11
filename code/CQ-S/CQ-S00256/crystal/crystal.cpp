#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,s[500005];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			++s[a[i]+a[j]];
		}
	}
	sort(s,s+n);
	cout<<s[n];
} 
