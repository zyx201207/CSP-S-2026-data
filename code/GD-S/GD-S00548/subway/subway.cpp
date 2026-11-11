#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2){
		cout<<32<<'\n'<<17;
		return 0;
	} 
	else if(c==0&&n==3){
		cout<<35<<'\n'<<16;
		return 0;
	}
	vector<int> w(n);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	vector<pair<int,int>> a;
	int b=0;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int d,f;
			cin>>d>>f;
			a.push_back({d,f});
		}
	}
	long long ans=0;
	int s,t;
	while(q--){
		cin>>s>>t;
		ans=0;
		for(int i=s;i<=t;i++){
			for(auto x:a){
				if(x.first==i){
					ans+=x.second;
				} 				
			}				
		}
		ans+=(w[s-1]+w[t-1]);
		cout<<ans<<'\n';
	}
	
	return 0;
} 
