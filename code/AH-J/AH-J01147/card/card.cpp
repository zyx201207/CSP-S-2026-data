#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],b[200050],c[200050],i,j,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			b[a[j]]++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			c[i]+=b[j];
		}
	}
	for(i=1;i<=n;i++){
		if(c[i]!=0)cout<<c[i]<<" ";
	}
	return 0;
}
