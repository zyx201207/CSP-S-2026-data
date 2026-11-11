#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10000003];
int k;int a[10000];
int t[10000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int j=1;j<=k;j++){
		cin>>a[j]>>t[j];
	}
	for(int i=1;i<=k;i++){
		int x,y;
		int time=0;
		cin>>x>>y;
		time+=w[x]+w[y];
		time+=t[y];
		cout<<time;
	}
	return 0;
	
}
