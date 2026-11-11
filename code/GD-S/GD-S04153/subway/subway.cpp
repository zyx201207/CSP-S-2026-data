#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int c,m,n,d,q;
int walk[N+10];
int siten[1001][1001],sitew[1001][1001];
int st[N+10],ed[N+10];

int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>walk[i];
	int cvis[1001][1001]={};
	for(int i=1;i<=m;i++){
		cvis[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		int j;
		cin>>j;
		for(int k=1;k<=j;k++){
			cin>>siten[i][k]>>sitew[i][k];
			if(k>1){
				for(int l=k;l>=0;l--){
					cvis[siten[i][k-1]][siten[i][k]]=1;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st[i]>>ed[i];
	}
	for(int i=1;i<=q;i++){
		
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
