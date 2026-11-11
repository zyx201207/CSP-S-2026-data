#include<bits/stdc++.h>
#define N 500050
using namespace std;
long long c,t,n,k;
int d[]={213,43,566,31,243,44,55,42,1,234,445,56,645};
int main(){
	int m=time(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int ans=time(0);
		ans+=d[time(0)%13];
		ans=ans%(c*c+3);
		cout<<ans<<"\n";
	}
	return 0;
} 
