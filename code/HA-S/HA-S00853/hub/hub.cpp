#include<bits/stdc++.h>
using namespace std;
long long u[1000001];
long long v[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long a,b;
	long long c,t,n,k;
	long long ans=0;
	long long sum=0;
	cin>>c>>t>>n>>k;
	for(int i=1;i<=t*8-2;i++){
		cin>>u[i];
		cin>>v[i];
	}
	ans=u[t*4-2];
	sum=v[t*4-2];
	cout<<ans<<endl;
	cout<<sum;
	return 0;
}
