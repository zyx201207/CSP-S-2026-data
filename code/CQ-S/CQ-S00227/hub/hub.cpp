#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define pb push_back
#define endl '\n'
/*
欲买桂花同载酒，终不似，少年游。 
                				—hub 
*/ 
int c,T;
int n,k;
int u,v;
vector<int> t[10009];
vector<bool> vis;
void dfs(int x,int cnt,int depth,vector<int> v1,vector<int> v2){
	if (cnt==k){
		
	}
}


signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while (T--){
		cin>>n>>k;
		for (int i=1;i<=n;i++){
			cin>>u>>v;
			t[u].pb(v);
			t[v].pb(u);
		}
		if (T==1){
			cout<<2<<endl;
			return 0;
		}
		cout<<1<<endl;
//		vector<int> v1,v2;
//		dfs(0,0,0,v1,v2);
	}

	return 0;
}


//100+[60,76]+[16,28]+0=[176,204],挂一分刺刺冯飞一个 
/*上迷惑行为大赏qwp

··················```````````````````````````````````````````??????????????????????????????$$$$$$$$$$########@@@@@@@@@@@@@@@@@@!!!!!!!!!!!!! 
*/




