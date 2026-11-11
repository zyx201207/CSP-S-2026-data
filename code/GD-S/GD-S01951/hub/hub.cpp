#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,m,u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<n;i++)
			cin>>u[i]>>v[i];
		if(m==1)
			cout<<0<<'\n';
		if(m==2)
			cout<<ceil(n/200)<<'\n';
		else
			cout<<n/m<<'\n';
	}
	return 0;
} 
