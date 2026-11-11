#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=5e5+5;
int a[maxn],b[maxn],c[maxn];
bool d[maxn];
int n,m,ans;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=1;
		for(int j=1;j<=m;j++) d[j]=false;
		for(int j=1;j<=n;j++) c[j]=0;
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(d[k]==false){
				c[ans]=k;
				d[k]=true;
				ans++;
			}
			else{
				for(int x=1;x<=m;x++){
					if(c[x]==k){
						ans=x+1;
						break;
					}
				}
				for(int x=ans;x<=m;x++){
					d[c[x]]=false;
					c[x]=0;
				} 
			}
		}
		for(int j=1;j<=m;j++) b[c[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
