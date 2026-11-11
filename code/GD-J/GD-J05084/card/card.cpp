#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],al[N],b[N],c[N],k[N],xb=1,x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[ i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]){
				b[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		xb=i;
		while(1){
			if(b[xb]==0)c[++x]=a[xb],xb++;
			else xb=b[xb];
			if(xb>n)break;
		}
		for(int j=1;j<=x;j++)k[c[j]]++;
		for(int j=1;j<=n;j++)c[j]=0;
		xb=x=0;
	}
	for(int i=1;i<=m;i++)cout<<k[i]<<" ";
	return 0;
} 
