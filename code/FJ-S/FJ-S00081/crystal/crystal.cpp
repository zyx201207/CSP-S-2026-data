#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxn;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	int sm=m;
	for(int i=1;i<n;i++){
		if(a[i-1]<a[i]&&i!=1){
			c[i]=1; 
			b[i]=i;
			d[i]=a[i-1];
		}else{
			b[i]=b[i-1];
			c[i]=c[i-1]+1;
			d[i]=d[i-1];
		}
	}for(int i=2;i<=n;i++){
		if(a[i+1]==a[i]&&i!=n){
			continue;
		}
		int jm=(a[i]-d[i]);
	}                                                             
	return 0;
}
