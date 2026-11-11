#include <bits/stdc++.h>
using namespace std;
int a[200010],b,c,d[200010],ans,n,m,x;
int z[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		x=k;
		c=0;
		for(int i=x;i<=n;i++){
			c++;
			d[c]=a[i];
			for(int j=1;j<=c;j++){
				if(a[i]==d[j]){
					c=j;
				}
			}
		}
		for(int i=1;i<=c;i++){
			z[d[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0;	
}
