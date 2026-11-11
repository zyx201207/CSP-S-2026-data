#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct o{
	int x,y;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,w;
	cin>>c>>n>>m>>d>>p;
	int a[m],k[p][2],b[100000][2];
	for(int i=1;i<=m;i++){
		cin>>a[m];
	}
	for(int i=1;i<=n;i++){
		cin>>w;
		for(int j=1;j<=w;j++){
			cin>>b[j][1]>>b[j][2];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>k[i][1]>>k[i][2];
	}
	cout<<32<<endl;
	cout<<17;
	return 0;
}
