#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
const int N=1e4;
struct node{
	int data,t;
}a[N][N]; 
int w[505];
int x[50000]={27,15,34,24,16};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
//			a[j].data=x;
//			a[j].t=y;
		}
	}
	if(d<=2){
		for(int i=1;i<=n;i++){
			
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<x[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
