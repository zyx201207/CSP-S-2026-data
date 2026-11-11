#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],t[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int zhcf=i;
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++){
			if(t[a[j]]==1) zhcf=j,memset(t,0,sizeof t),t[a[j]]=1;
			else t[a[j]]=1; 
		}
		for(int j=zhcf;j<=n;j++){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
