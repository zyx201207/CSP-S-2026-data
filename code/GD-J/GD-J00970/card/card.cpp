#include<bits/stdc++.h>
using namespace std;
int a[500001],s[500001],g[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=0;
	}
	for(int k=1;k<=n;k++){
		int o=0;
		for(int i=k;i<=n;i++){
			s[o]=a[i];
			for(int j=0;j<o;j++){
				if(a[i]==s[j]){
					for(int l=j;l<=o;l++){
						s[l]=0;
						o--;
					}
					s[o]=a[i];
				}
			}
			o++;
		}
		for(int i=0;i<o;i++){
			g[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<g[i]<<" ";
	}
	return 0;
}
