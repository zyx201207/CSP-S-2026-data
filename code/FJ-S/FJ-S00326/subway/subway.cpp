#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
struct node{
	int a,t;
}s[100][100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int t1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>s[i][j].a>>s[i][j].t;
			t1=s[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<abs(y-x)*t1<<endl;
	}
	return 0;
}
