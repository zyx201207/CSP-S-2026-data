#include<bits/stdc++.h>
using namespace std;
struct node{
	int xb,c=0;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> w(n),a(n),f(m+2,0);
	vector<node> d(m+2);
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		int xb=0;
		for(int i=1;i<=m;i++) d[i].c=0;	
		for(int i=j;i<=n;i++){
			if(d[w[i]].c>0){
				for( ;xb>d[w[i]].xb;xb--){
					d[a[xb]].c=0;
				}
				xb=d[w[i]].xb+1;
			}else{
				d[w[i]].c=1;
				d[w[i]].xb=xb;
				a[xb]=w[i];
				xb++;
			}
		}
		for(int i=0;i<xb;i++){
			f[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
	return 0;
}
         
