#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<n;i++){
		for(int j=i+ans;j<=n;j++){
			long long k=(j-i)*a[j];
			long long ss=s[j-1]-s[i-1];
			if(k-ss>m)break;
			ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
