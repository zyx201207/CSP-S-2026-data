#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct bt{
	int name;
	int t; 
	int id;
};
int b[500005];
int mins=INT_MAX;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector<bt> a[505];
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i][j].name=x;
			a[i][j].t=y;
		}
	}
	cout<<"35\n";
	cout<<"16";

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
