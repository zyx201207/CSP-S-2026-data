#include<bits/stdc++.h>
using namespace std;
int w[500100];
int h[300100];
int o[300010]={};
int g[300010]={};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int k=1;k<=n;k++){
		memset(o,0,sizeof o);
		memset(g,0,sizeof g);
		for(int i=k;i<=n;i++){
			g[w[i]]++;
			if(g[w[i]]>1){
				for(int j=i-1;j>=o[g[w[i]]];j--){
					if(g[w[j]]>0) g[w[j]]--;
				}
			}
			o[g[w[i]]]=i;
		}
		for(int i=1;i<=m;i++){
			if(g[i]>0) h[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	//Hello CCF
	return 0;
}
