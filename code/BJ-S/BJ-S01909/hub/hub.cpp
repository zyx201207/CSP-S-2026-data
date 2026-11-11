#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> G[2000000];
int kk[2000000]={0};
int find(int fa,int dep,int now){
	for(int i=0; i<kk[now]; i++){
		int v=G[now][i];
		if(v==fa) return dep-1;
		find(now,dep++,v);
	}
	return dep-1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n;
		int ti=random();
		cout << ti%n << endl;
	}
	return 0;
}
