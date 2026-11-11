#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int mm[300005];
vector<int>f[300005];
void fix(int x){
	int b=a[x];
	int lw=x;
	for(int i=n;i>=x+1;i--){
		if(a[i]==b){
			lw=i;
			break;
		}
	}
	if(lw!=x){
		for(int i=0;i<f[lw].size();i++){
			f[x].push_back(f[lw][i]);
		}
	}
	else{
		f[x].push_back(b);
		for(int i=0;i<f[x+1].size();i++){
			f[x].push_back(f[x+1][i]);
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[n].push_back(a[n]);
	mm[a[n]]++;
	for(int i=n-1;i>=1;i--){
		fix(i);
		for(int j=0;j<f[i].size();j++)mm[f[i][j]]++;
	}
	for(int i=1;i<=m;i++)cout<<mm[i]<<' ';
	return 0;
}
