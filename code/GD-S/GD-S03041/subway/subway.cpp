#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,distanse[500005],number,k,a[500005][2],j,y;
struct node{
	int pass[25];
	int time;
}route[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>distanse[i];}
	for(int i=1;i<=n;i++){
		cin>>number;
		for(int j=1;j<=number;j++){cin>>route[i].pass[i]>>route[i].time;}
	}
	int l=route[1].time;
	for(int i=1;i<=q;i++){
		cin>>j>>y;
		int all=distanse[j]+distanse[y];
		all+=(y-j)*l;
		cout<<all<<endl;
	}
	return 0;
}
