#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long a[N],s[N];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		s[i]=a[i+1]-a[i];
		//cout<<s[i]<<" ";
	}
	sort(s+1,s+n+1);	
	long long ans=0,sum=0;
	for(int i=1;i<n;i++){
		sum=s[i]*i;
		if(ans+sum<m)ans+=sum;
		if(ans+sum==m){
			cout<<i;
			return 0;
		}
		if(ans+sum>m){
			cout<<i-1;
			return 0;
		}
	}

	return 0;
} 
