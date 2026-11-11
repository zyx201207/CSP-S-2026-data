#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int c[MAXN],s[MAXM];
bool d[MAXM];
int n,m;
int dfs(int x){
	int su=x;
	bool u[MAXN];
	memset(u,0,sizeof(u));
	vector<int>r;
	for(int i=x+1;i<=n;i++){
		if(!u[c[i]]){
			r.push_back(c[i]);
			u[c[i]]=1;
		}
	}
	if(r.size()==0)return su;
	for(int i=x-1;i>=0;i++){
		if(c[i]==c[x])break;
		for(int j=0;j<r.size();j++){
			if(r[j]==c[i])su-=dfs(i);
		}
		
	}
	return su;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	memset(s,0,sizeof(s));
	memset(d,0,sizeof(d));
	for(int i=n;i>=1;i--){
		if(d[c[i]])continue;
		d[c[i]]=1;
		s[c[i]]=dfs(i);
	}
	for(int i=1;i<=m;i++){
		cout << s[i] << " ";
	}
	return 0;
}
