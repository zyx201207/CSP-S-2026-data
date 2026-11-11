#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[500010],t,q,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		t=p=i,q=n-i+1;
		for(;q>0;q--,p++,t++){
			c[t]=a[p];
			for(int k=i;k<t;k++)
				if(c[t]==c[k])
					t=k;
		}
		for(int j=i;j<t;j++)
			b[c[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<' ';
	return 0; 
}
