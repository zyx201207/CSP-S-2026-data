#include<bits/stdc++.h>
using namespace std;
int dfs_besttime=99999;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long a=0,b=0,c=0,d=0,e=0;
	cin>>a>>b>>c>>d>>e;
	vector<long long> f;
	for(int i=0;i<c;i++){
		int g=0;
		cin>>g;
		f.push_back(g);
	}
	vector<int> state;
	vector<int> tm;
	for(long long i=0;i<b;i++){
		long long gg=0;
		cin>>gg;
		if(gg%2!=0) gg=gg/2+1;
		else gg/=2;
		for(long long o=0;o<gg;o++){
			long long gh=0,wtw=0;
			cin>>gh>>wtw;
			state.push_back(gh);
			tm.push_back(wtw);
		}
	}
	int plan[e][2]={0};
	for(long long i=0;i<e;i++){
		cin>>plan[i][0]>>plan[i][1];
	}
	for(long long i=0;i<e;i++){
		long long tisme=0;
		long long gg=0,ff=0;
		for(long long o=0;o<state.size();o++){
			if(state[o]==plan[i][0]){
				gg=o;
			}
			if(state[o]==plan[i][1]){
				ff=o;
			}
		}
		tisme+=tm[gg]+tm[ff]+f[plan[i][0]-1]+f[plan[i][1]-1];
		cout<<tisme<<endl;
	}
	return 0;
} 
