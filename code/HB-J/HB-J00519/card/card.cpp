#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ten year oi one groud null no open long long meet grandfather
int ti[5005];
int ans[5005];
int y[100005];
int u,ds,n,m;
int cz(){
	for(int i=n;i>=ds;i--){
		if(ti[y[i]]>1)return i;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>y[i];
		ti[y[i]]++;
	}
	ds=0;
	u=cz();
	while(ds<=n){
		ti[y[ds]]--;
		ds++;
		if(ti[u]<=1){
			u=cz();
		}
		if(u==0){
			for(int i=ds;i<=n;i++){
				ans[y[i]]++;
			}
		}
		else{
			for(int i=u;i<=n;i++){
				ans[y[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
