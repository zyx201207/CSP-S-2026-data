#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,c;
int a[1000010],g[500][500];
struct node{
	int z,t;
}x[1000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int xi;
		cin>>xi;
		for(int i=1;i<=xi;i++){
			cin>>x[i].z>>x[i].t;
			g[i][x[i].z]=x[i].t;	
		}
	}
	int st,en,sum=0,dq;
	for(int i=1;i<=q;i++){
		cin>>st>>en;
		dq=st;
		sum+=a[dq];
		if(st!=en){
			sum+=g[dq][dq+1];
		}
		cout<<sum<<endl;
	}
	return 0;
}
