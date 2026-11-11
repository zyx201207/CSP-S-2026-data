#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k;
vector<int> v[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0)); 
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)
			v[i].clear();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int st,ed;
			cin>>st>>ed;
			v[st].push_back(ed);
			v[ed].push_back(st);
		}
		cout<<(n-1)/2<<"\n";
	}
	return 0;
}

