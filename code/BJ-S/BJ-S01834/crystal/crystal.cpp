#include<bits/stdc++.h>
using namespace std;
int n,m,dcnt,ans=0;
int a[500005],c[500005];
int dc[500005];
void dfs(int x){
	if(x>n){
		if(dcnt!=m){
			return;
		}
		map<int,int>ac;
		for(int i=1;i<=n;i++){
			ac[a[i]]++;
			ans=max(ans,ac[a[i]]);
		}
		return;
	}
	for(int i=0;i<=m;i++){
		dcnt+=i;
		a[x]+=i;
		if(dcnt>m){
			dcnt-=i;
			a[x]-=i;
			break;
		}
		dfs(x+1);
		a[x]-=i;
		dcnt-=i;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cntdc=a[2]-a[1],pdc=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cntdc){
			pdc=0;
			break;
		}
	}
	if(pdc==1){
		int cnt=cntdc;
		int mc=m/cnt;
		int dc=0;
		for(int i=1;i<=n+10;i++){
			dc+=i;
			if(dc>mc){
				cout<<i-1;
				return 0;
			}
		}
	}
	else{
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
