#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,x,y,a[N];
struct s{
	int q,e;
}b[2000][2000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>n;
	cin>>n>>m>>x>>y;
	for(int i = 1;i <= m;i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n;i++){
		int z;
		cin>>z;
		for(int j = 1;j <= 2*z;j++){
			cin>>a[i][j].x>>a[i][j].y;
		}
	}
	for(int i = 1;i <= y;i++){
		int d,f;
		cin>>d>>f;
	}
	return 0;
}
