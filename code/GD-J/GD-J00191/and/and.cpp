#include<bits/stdc++.h>
using namespace std;
long long s,n,m,h[1000100],a[1000100],dp[1000010],s1,s2,s3;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>h[1];
	s2=h[1];
	for(int i=2;i<=n;i++){
		cin>>h[i];
		s1&=h[i];
		s2=max(h[i],s2);
	}
	if(n==m){
		cout<<s1;
		return 0;
	}
	if(m==1){
		cout<<s2;
		return 0;
	}
	if(m==2&&n<=10000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s3=max(s3,h[i]&h[j]);
			}
		}
		cout<<s3;
		return 0;
	}
	sort(h+1,h+1+n);
	cout<<h[n-m+1];
	return 0;
}
