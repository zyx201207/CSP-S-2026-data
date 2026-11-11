#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,sum,a[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=501){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			memset(c,0,sizeof c);
			memset(d,0,sizeof d); 
			int len=0;
			for(int j=i;j<=n;j++){
				for(int k=1;k<=len;k++){
					if(c[k]==a[j]){
						len=k-1;
						break;
					}
				}
				c[++len]=a[j];
			}
			for(int j=1;j<=len;j++) d[c[j]]=1;
			for(int j=1;j<=m;j++) if(d[j])b[j]++; 
		}
		for(int i=1;i<=m;i++) cout<<b[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++){
			c[a[j]]++;
		}
		for(int j=1;j<=m;j++) if(c[j])b[j]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
