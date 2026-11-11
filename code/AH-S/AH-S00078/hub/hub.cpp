#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	long long t1,c,t;
	cin>>c>>t;
	t1=t;
	while(t--){
		long long n,k,u,v;
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u>>v;
		cout<<t1-t<<endl;
	}
	return 0;
}
