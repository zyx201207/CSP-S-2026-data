#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=3e5+10; 
int n,m;
int a[N];
int b[M];
int main(){
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int g[N],G;
		bool p[M];
		for(int _=1;_<=m;_++){
			p[_]=0;
		}
		G=0;
		for(int j=i;j<=n;j++){
			if(!p[a[j]]){
				G++;
				g[G]=a[j];
				p[a[j]]=1;
			}
			else {
				while(g[G-1]==a[j]){
					G--;
				}
				p[a[j]]=0;
			} 
		}
		for(int k=1;k<=G;k++){
			cout<<i<<' '<<g[k]<<'\n';
			b[g[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}

