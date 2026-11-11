#include<bits/stdc++.h>
using namespace std;
int e[500005];
int color[300005];
int n,m;
void game(int start){
	vector<int> f(n+n+2,0);
	vector<bool> colour(m+1,0);
	int h=n;
	//for(int i=1;i<=n;++i)f[i]=e[i];
	for(int i=start;i<=n;++i){
		int root=-1;
		for(int j=1;j<=h;++j){
			if(e[i]==f[j]){
				root=j;
				break;
			}
		}
		if(root==-1){
			++h;
			f[h]=e[i];
		}
		else{
			h=root;
		}
	}
	for(int i=1;i<=h;++i){
		colour[f[i]]=1;
	}
	
	for(int i=1;i<=m;++i){
		color[i]+=colour[i];
		//cout<<colour[i]<<' ';
	}//cout<<'\n';
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//BAOLI
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>e[i];
	}
	for(int i=1;i<=n;++i){
		game(i);
	}
	for(int i=1;i<=m;++i){
		cout<<color[i]<<' ';
	}
	return 0;
}
