#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
long long s[N];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[n+1]=a[n];
	for(int i=1;i<=n;i++){
		s[i+1]+=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+s[i]*(i-1);
	}
	int j=1;
	for(int i=1;i<=n;i++){
		while(((s[i]-s[j-1]-(a[i]-a[j])*(j-1))>m) && (j<i)){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
