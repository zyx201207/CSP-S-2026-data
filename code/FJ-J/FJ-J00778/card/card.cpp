#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],z[500001],w[300001],g,s[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		g=0;
		for(int j=0;j<=n;j++){
			z[j]=0;
		}
		for(int j=0;j<=m;j++){
			w[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(w[a[j]]){
				g=w[a[j]];
			}
			else{
				z[++g]=a[j];
				w[a[j]]=g;
			}
		}
		for(int j=1;j<=g;j++){
			s[z[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
