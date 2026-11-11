#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,b,a[200002][32],c[200002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&b);
		int j=1,o=1;
		while(b>0){
			a[i][j]=b%2;
			b/=2;
			j++;
			o*=2;
		}
		k=max(k,j-1);
		y=max(y,o);
	}
	b=0;
	for(int i=k;i>=1;i--){
		int x=0;
		y/=2;
		for(int j=1;j<=n;j++) if(a[j][i]==1&&c[j]!=1) x++;
		if(x>=m){
			for(int j=1;j<=n;j++) if(a[j][i]==0) c[j]=1;
			b+=y;
		}
	}
	cout<<b;
	return 0;
}
