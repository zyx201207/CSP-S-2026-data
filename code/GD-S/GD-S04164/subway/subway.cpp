#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],tmp,stp[500005];
vector<long long>state2line[505];
long long k[500005+2];
vector<long long>a[500005+1],t[500005+1];
long long dfs(long long x,long long y){
	long long mn=1000000000000000000;
	if(x==y)return stp[y];
	else{
		for(long long i=0;i<state2line[x].size();i++){
			long long _1=stp[state2line[x][i]];
			long long _2=t[x][i]+stp[x]+t[state2line[x][i]][i]; 
			if(_1>_2){
				stp[state2line[x][i]]=t[x][i]+stp[x]+t[state2line[x][i]][i];
				mn=min(mn,stp[state2line[x][i]]+dfs(x,y));
			}
		}
	}
	return mn;
}
void problem(int mark){
	int x_,y_;
	cin>>x_>>y_;
	for(int i=1;i<=n;i++)stp[i]=1e18;
	cout<<w[x_]+dfs(x_,y_)+w[y_];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>tmp;
			a[i].push_back(j);
			state2line[a[i][a[i].size()-1]].push_back(i);
			cin>>tmp;
			t[i].push_back(j);
		}
	}
	for(int i=1;i<=q;i++){
		problem(i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
