#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,t;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=a[1];
	if(m==n){
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n]<<'\n';
		return 0;
	}
	if(m==2){
		ans=INT_MIN;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				t=a[i]&a[j];
				ans=max(ans,t);
			}
		cout<<ans<<'\n';
		return 0;
	} 
	for(int i=1;i<=m;i++)
		ans=ans&(a[n-i+1]);
	cout<<ans<<'\n';
	return 0;
}
