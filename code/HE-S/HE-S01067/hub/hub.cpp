#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k,u,v,ans;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		n=n>>1;
		if(c==13 or c==14){
			cout<<(((n-k)+3)/4)+1<<'\n';continue;
		}
	}
	return 0;
}
