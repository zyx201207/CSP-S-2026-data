#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int d2[500005];
int d3[300005];
bool complain(int k,int f){
	for(int i=1;i<=f;++i) if(d2[i]==k){
		return 1;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		memset(d2,0,sizeof(d2));
		for(int j=i;j<=n;++j){
			if(complain(a[j],i)){
				int k=n+1;
				while(d2[k]==a[j]){
					d2[k]=0;k--;
				}
			}else d2[j]=a[j];
		}
		for(int j=1;j<=n;++j){
			d3[d2[j]]++;
		}
	}
	for(int j=1;j<=m;++j) cout<<d3[j]<<' ';
	return 0;
}
