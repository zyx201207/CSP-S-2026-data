#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],nx[500010],d[500010],ans[500010],f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		nx[i]=d[a[i]];
		d[a[i]]=i;
	}
	memset(d,0,sizeof d);
	for(int i=1;i<=n;i++){
		d[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(d[i]==0) continue;
		int j=d[i];
		while(j<=n){
			if(nx[j]==0){
				ans[a[j]]+=f[i];
				j++;
			}
			else{
				j=nx[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

