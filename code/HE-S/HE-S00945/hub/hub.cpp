#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long o=0;o<t;o++){
		long long n,k,ans=INT_MAX;
		cin>>n>>k;
		for(long long i=1;i<n;i++){
			long long a,b;
			cin>>a>>b;
			ans=min(ans,abs(a-b));
		}
		if(o==t-1)  ans++;
		cout<<ans<<endl; 
	} 
	return 0;
}
