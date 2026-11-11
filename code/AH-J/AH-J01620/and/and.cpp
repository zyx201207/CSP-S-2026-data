#include<bits/stdc++.h>
#define M 29 //2^29
using namespace std;
vector<int> bi[32];
vector<int> a;
int n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	a.resize(n);
	for(auto &p:a){
		cin>>p;
		for(int i=M;i>=0;i--)
			if(p&(1<<i))
				bi[i].push_back(p);
	}
//	for(int i=0;i<=M;i++) sort(bi[i].begin(),bi[i].end(),greater<int> ());
//	sort(a.begin(),a.end(),greater<int> ());
	for(int i=M;i>=0;i--){
		if(bi[i].size()>=m){
			ans+=(1<<i);
			a=bi[i];
			for(int i=0;i<=29;i++) bi[i].clear();
			for(auto &p:a)
				for(int i=M;i>=0;i--)
					if(p&(1<<i))
						bi[i].push_back(p);
//			for(int i=0;i<=29;i++) sort(bi[i].begin(),bi[i].end(),greater<int> ());
		}
	}
	cout<<ans;
	return 0;
}
