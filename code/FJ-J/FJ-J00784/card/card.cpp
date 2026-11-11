#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[5005][3005],c[300005],d[300005],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[n][a[n]]=1;
	b[n][0]=a[n];
	c[a[n]]=n;
	for(int i=n-1;i>=1;i--){
		if(c[a[i]]==0) k=i+1;
		else k=c[a[i]];
		for(int j=1;j<=m;j++){
			b[i][j]=b[k][j];
			d[j]+=b[i][j];
		}
		b[i][a[i]]=1;
		c[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]+1<<" ";
	}
	return 0;
}
