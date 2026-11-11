#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans,len;
ll m,a[N],s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) {
		a[i]=a[i+1]-a[i];
		s[i]=s[i-1]+a[i]*i;
		/*
		cout<<a[i]<<" ";
		*/
	}
	/*
	cout<<"\n";
	for(int i=1;i<n;i++) 
		cout<<s[i]<<" ";
	cout<<"\n";
	*/
	int id=upper_bound(s+1,s+n,m)-s;
	ans=s[id-1],len=id-1;
	/*
	cout<<id<<"\n";
	*/
	for( ;id<n;id++) {
		int x=s[id]-s[id-len-1],t=1;
		while(x<=m) {
			ans=x;
			if(id>len+(++t)) 
				x=s[id]-s[id-len-t];
			else break;
		}
		len+=t-1;
		/*
		cout<<ans<<" "<<len<<"\n";
		*/
	}
	cout<<len+1;
	
	return 0;
}
