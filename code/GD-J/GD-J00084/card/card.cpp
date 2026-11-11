#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],ans[3005],ha[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	memset(ans,0,sizeof(ans));
	memset(ha,0,sizeof(ha));
	for(int i=1;i<=n;++i){
		int l=i;
		memset(ha,0,sizeof(ha));
		for(int j=i;j<=n;++j){
			if(ha[a[j]]>=l)
				l=max(l,j);
			ha[a[j]]=j;
		}
		for(int j=1;j<=m;++j){
			if(ha[j]>=l) ans[j]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
2 3 1 2 1 3 2 3 1 2 1
*/
