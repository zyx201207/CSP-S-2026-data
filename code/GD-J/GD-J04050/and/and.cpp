#include<bits/stdc++.h>
using namespace std;

#define N 200005

bool bit[N][32];
priority_queue<int> has[32];
vector<int> must;
vector<int> newm;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		int c=0;
		while(a){
			bit[i][c]=a&1;
			a>>=1;
			c++;
		}
	}
	
	for(int i=n;i>=1;i--){
		for(int j=0;j<32;j++){
			if(bit[i][j]) has[j].push(i);
		}
		must.push_back(i);
	}

	int ans=0;
	for(int i=31;i>=0;i--){ 
		int ptr=0;
		while(!has[i].empty() && ptr<must.size()){
			int c=has[i].top();has[i].pop();
			while(c<=must[ptr] && ptr<must.size()){
				if(c==must[ptr++]){
					newm.push_back(c); 
				}
			}
		}
		//cout<<newm.size()<<'\n';//debug
		if(newm.size() < m){
			//cout<<i<<" disable\n";//debug
			newm.clear();
			continue;
		}
		//cout<<i<<" able\n";//debug
		ans|=(1<<i);
		must.clear();
		for(int j=0;j<newm.size();j++){
			must.push_back(newm[j]);
			//cout<<newm[j]<<' ';//debug
		}
		//cout<<'\n';//debug
		newm.clear();
	}
	cout<<ans<<'\n';
	return 0;
}

