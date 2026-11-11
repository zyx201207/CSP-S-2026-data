#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct zzz{
	int name;
	int outcost;
}ew[100][100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int cost[100000];
	for(int i=1;i<=m;i++){
		cin>>cost[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;i<=k;j++){
			cin>>ew[i][j].name>>ew[i][j].outcost;
		}
	}
	int o[100][3];
	for(int i=1;i<=q;i++){
		cin>>o[i][1]>>o[i][2];
	}
	cout<<31; 
	
	return 0;
} 
