#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		d[0]=0;
		for(int j=i;j<=n;j++){
			int id=0;
			for(int k=1;k<=d[0];k++){
				if(d[k]==a[j]){
					id=k;
					break;
				}
			}
			if(id!=0){
				d[0]=id-1;
			}
			d[++d[0]]=a[j];
		}
		for(int j=1;j<=d[0];j++){
			c[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
