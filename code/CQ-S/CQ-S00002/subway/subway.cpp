#include<bits/stdc++.h>
using namespace std;
long long xxzzz,n,m,d,q,mn=1e9;
long long t[500005];
map<long long,long long> mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>xxzzz>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(int j=1;j<=x;j++){
			long long a,b;
			cin>>a>>b;
			mn=min(mn,b);
			mp[a]=mn;
		}
	}
	for(int i=1;i<=q;i++){
		long long aaa,bbb;
		cin>>aaa>>bbb;
		cout<<mp[aaa]+t[aaa]+t[bbb]+mp[bbb]<<endl;
	}
	return 0;
} 

