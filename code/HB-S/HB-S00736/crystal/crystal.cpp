#include<bits/stdc++.h>
using namespace std;
const int man=5e5+10;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	long long a[man],c[man];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=(i-1)*(a[i]-a[i-1])+c[i-1];
	}
	int ans=upper_bound(c+1,c+1+n,m)-c;
	for(int i=2;i<n;i++){
		for(int j=i+1;j<=n;j++){
			c[j]=c[j]-c[i]-(a[j]-a[i]);
		}
		int ans2=(upper_bound(c+i,c+1+n,m)-c);
		ans=max(ans, ans2-i+1);
	}
	cout<<ans-1<<" ";
	return 0;
}
