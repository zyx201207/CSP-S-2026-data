#include<bits/stdc++.h>
using namespace std;
#define int long long
using p=pair<int,int>;
int dx[200009];
int a[200009];
map<int,int> mp;
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(mp.find(i)){
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
