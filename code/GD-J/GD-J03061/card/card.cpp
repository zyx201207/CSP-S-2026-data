#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[1200005],x;
long long c[1200005],d[1200005];
long long e[1200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			d[a[j]]=j;
			if(c[a[j]]>1&&j>x){
				x=j;
				c[a[j]]=1;
			}
		}
		x=i+1;
		c[1200005]={0};
		for(int l=x;l<=n;l++){
			e[a[l]]++;
		}
	}
	for(int i=1;i<m;i++) cout<<e[i]<<" "; 
	cout<<n;
	return 0;
}
