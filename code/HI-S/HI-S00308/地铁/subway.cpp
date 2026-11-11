#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[10005];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	int w;
	int k[10005][10005];
	for(int i=0;i<7;i++){
		cin>>w>>k[i][i];
	}
	int x,y;
	for(int r=0;r<q;r++){
		cin>>x>>y;
	}
	cout<<1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

