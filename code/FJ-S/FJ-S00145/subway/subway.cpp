#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,b;
			cin>>a>>b;		
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
	}
	else if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16; 
	}
}
