#include<bits/stdc++.h>
using namespace std;
struct node {
	bool flag=0;
	int location;
};
int n,m;
int a[500005];
int game[500005];
map<int,node> mp;
map<int,int> stay;
void game_clear() {
	for(int i=1; i<=n; i++) game[i]=0;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		game_clear();
		mp.clear();
		int t=0;
		for(int j=i; j<=n; j++) {
			if(mp[a[j]].flag) {
				for(int k=mp[a[j]].location+1; k<=t; k++) {
					mp[game[k]].flag=0;
					mp[game[k]].location=0;
					game[k]=0;
				}
				t=mp[a[j]].location;
			} else {
				mp[a[j]].flag=1;
				mp[a[j]].location=++t;
				game[t]=a[j];
			}
		}
		for(int j=1; j<=t; j++) stay[game[j]]++;
	}
	for(int i=1; i<=m; i++) cout<<stay[i]<<' ';
	return 0;
}
//Ren Boda
