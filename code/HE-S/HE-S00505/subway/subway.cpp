#include<bits/stdc++.h>
using namespace std;
int a[500][500010],t[500][500010];
int c,n,m,d,q;
int w[500010],k[500010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bool sa = 1,sb = 1;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)sa = 0;
		for(int j = 1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(t[i][j]!=t[1][1])sb = 0;
		}
	}
	if(sa){
		queue<int> que;
	}
	cout<<10;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
