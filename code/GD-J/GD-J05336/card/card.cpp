#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long t[300005]; 
long long b[500005],c[500005],vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,r,l;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		long long f=n-i+1,x=1;
		int j=i;
		while(f--){
			if(vis[b[j]]==0){
				c[x]=b[j];
				x++;
				vis[b[j]]=1;
			}else{
				for(int k=1;k<=j;k++){
					if(c[k]==b[j])r=k;
				}
				for(int k=r;k<=x;k++)c[k]=0;
				for(int k=r;k<=x;k++)vis[k]=0;
				x=r;
				c[x]=b[j];
				x++;
				vis[b[j]]=1;
			}
			j++;
		}
		for(int j=1;j<=x;j++){
			t[c[j]]++;
		}
		for(int k=0;k<=x;k++)c[k]=0;
		for(int k=0;k<=m;k++)vis[k]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
} 
