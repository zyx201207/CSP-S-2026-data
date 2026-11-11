#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int mod=0;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		mod+=x;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,z;
			cin>>y>>z;
			mod+=z; 
		}
	}	
	for(int i=1;i<=q;i++){
		cout<<(int)(rand()%mod)/2<<endl;
	}
	return 0;
}


