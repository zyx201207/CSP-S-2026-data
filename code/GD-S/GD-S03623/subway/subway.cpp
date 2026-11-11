#include <bits/stdc++.h>
using namespace std;
int w[500005]={0},a[500005]={0},t[500005]={0},x[500005]={0},y[500005]={0},k[500005]={0};
bool mp[505][505]={{0}};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	bool flag1=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			mp[i][a[j]]=1;
			mp[a[j]][i]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(flag1==0){
		for(int i=1;i<=n;i++){
			if(k[i]==2){
				mp[a[0]][a[1]]=1;
				mp[a[1]][a[0]]=1;
			}
		}
	}
	return 0;
}
