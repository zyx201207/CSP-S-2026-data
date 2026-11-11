#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],v[300005],p[300005],pl,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<300005;j++) p[j]=v[j]=0;
		pl=1;
		for(int j=i;j<n;j++){
			p[pl]=a[j];
			if(v[p[pl]]&&pl>v[p[pl]]) pl=v[p[pl]]+1;
			else{
				v[p[pl]]=pl;
				pl++;
			}
		}
		for(int j=1;j<pl;j++) ans[p[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
