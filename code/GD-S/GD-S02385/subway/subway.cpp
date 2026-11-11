#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int arrm[500010],k[30],way[510][30],t;
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>arrm[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			cin>>way[i][j]>>t;
		}
	}
	while(q--){
		int num=0;
		int s,e;
		cin>>s>>e;
		num+=arrm[s]+arrm[e]+2*t;
		cout<<num;
	}
	return 0;
}
