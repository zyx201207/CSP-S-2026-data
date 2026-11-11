#include<bits/stdc++.h>
using namespace std;
long long q,w,n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>q>>w;
	while(w--){
		vector<long long> a[50005];
		long long s[50005]={0};
		cin>>n>>m;
		long long o=0;
		for(int i=1;i<n;i++){
			long long y,u;
			cin>>y>>u;
			a[y].push_back(u);
			a[u].push_back(y);
			s[y]++;
			s[u]++;
		}
		for(int i=1;i<=n;i++){
			o=max(o,s[i]);
		}
		cout<<o/2<<endl;
	}
	
	return 0;
}
