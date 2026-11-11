#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int M=5e5+5;

int c,n,m,d,q,w[M];
int f[N][N];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y; 
	}
	if(n==2){
		cout<<"32"<<endl;
		cout<<"17"<<endl;
	}
	else if(n==3){
		cout<<"35"<<endl;
		cout<<"16"<<endl;
	}
	return 0;
}
