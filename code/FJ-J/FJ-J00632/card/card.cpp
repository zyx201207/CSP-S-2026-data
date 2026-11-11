#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],te[300010],no[300010],f[500010];
bool l=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			l=0;
		}
		if(no[a[i]]==1){
			f[te[a[i]]]=i;
		}
		no[a[i]]=1;
		te[a[i]]=i;
	}
//	for(int i=1;i<=n;i++){
//		cout<<f[i]<<' ';
//	}
	memset(no,0,sizeof(no));
	if(l){
		for(int i=1;i<=n+1;i++){
			if(a[i]!=a[i-1]){
				no[a[i-1]]=i-1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<no[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(te,0,sizeof(te));
		for(int j=i;j<=n;j++){
			while(f[j]!=0){
				j=f[j];
			}
			te[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			no[j]+=te[j];
//			cout<<te[j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<no[i]<<' ';
	}
	return 0;
}/*10 3
3 1 2 1 3 2 3 1 2 1*/
