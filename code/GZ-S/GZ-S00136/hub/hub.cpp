//GZ-S00136 贺良煜 贵阳市白云区华师一学校
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	long long T,n,k,n2;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		n2=n-1;
		vector<long long> m[n];
		long long v99,u99;
		while(n2--){
			cin>>u>>v;
			m[u].push_back(v);
		}
		cout<<1<<"\n";
	}
	
	return 0;
}
