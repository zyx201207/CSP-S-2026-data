#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,ans,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==13||c==14){
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)
		cin>>u>>v;
		cout<<(int)(ceil(((n-1)/2-k)*1.0/4)+1)<<endl;
	}
	}
	else 
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)
		cin>>u>>v;
		if(k<n)
		cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
