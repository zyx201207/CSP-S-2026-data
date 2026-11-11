#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[510000],bk[510000],ans[310000];
bool h[510000] = {0};//0:huo,1:die
int st[310000] = {0};

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	bool pd = 1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] < a[i-1]) pd = 0;
	}
	if(pd){
		//special test A
		for(int i=1;i<=n;i++){
			st[a[i]] = i;
		}
		for(int i=1;i<=m;i++){
			cout<<st[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) h[j] = 0,bk[j] = 0;
		for(int j=1;j<=i-1;j++){
			h[j] = 1;
		} 
		for(int j=i;j<=n;j++){
			if(bk[a[j]]){
				for(int k=bk[a[j]];k<j;k++){
					if(!h[k]) bk[a[k]] = 0;
					h[k] = 1;
				}
			}
			bk[a[j]] = j;
		} 
		
		for(int j=1;j<=m;j++){
			if(bk[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
//copy by baibai__
//about 40pts - 52pts