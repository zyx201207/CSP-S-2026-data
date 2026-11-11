#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,l,r;
long long w[1000005];
struct node{
	long long zhan;
	long long time;
};
node a[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin<<w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m+n;j++){
			cin>>a[i][j].zhan>>a[i][j].time;
		}
	}
	return 0;
	}

