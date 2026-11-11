#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<ll>a(n);
	vector<char>b(n);
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	ll ans=0;
	for(int i=0,j=n-1;i<j;){
		ll len=min(a[i],a[j]);
		a[i]-=len,a[j]-=len;
		if(b[i]!=b[j])ans+=len;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	return 0;
} 
