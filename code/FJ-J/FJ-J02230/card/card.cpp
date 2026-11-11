#include<bits/stdc++.h>
using namespace std;
long long n,jj,m,a[500005],c[500005],b[500005],v=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		jj=i;
		for(int j=i;j<=n;j++,jj++){
			for(int k=i;k<=jj;k++){
				if(b[k]==a[j]&&a[j]!=0) v=1;
				if(v) {
					b[k]=0;	
				}
			}
			v=0;
			b[jj]=a[j];
		}
		for(int j=1;j<=jj;j++){
			c[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
}
