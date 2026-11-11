#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>game;
		for(int j=i;j<=n;j++){
			auto it=find(game.begin(),game.end(),a[j]);
			if(it==game.end()){
				game.push_back(a[j]);
			}else{
				game.erase(it,game.end());
				game.push_back(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			if(find(game.begin(),game.end(),i)!=game.end())ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
