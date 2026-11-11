#include<bits/stdc++.h>
using namespace std;
const int MAXN=400050;
const int MAXM=400050;
int n, m, a[MAXN], b[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		int dt[MAXN]={}, pos=0;
		bool vis[MAXM]={};
		for(int j = i; j < n; j++){
			dt[pos++]=a[j];
			for(int k = 0; k < pos-1; k++){
				if(dt[k]==dt[pos-1]){
					for(; k < pos-1; k++) dt[k]=-1;
					break;
				}
			}
		}
		for(int j = 0; j < pos; j++){
			if(dt[j]!=-1 && !vis[dt[j]]){
				b[dt[j]]++;
				vis[dt[j]]=1;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
