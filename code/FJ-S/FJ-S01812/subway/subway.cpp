#include <bits/stdc++.h>
using namespace std;
int main(){
	
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[500005];
	int t[500005][500005];
	cin>>c>>n>>m>>d>>q;
	//cout<<"input w"<<endl;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	//cout<<"input k"<<endl;
	for(int i=0;i<n;i++){
		int ki;
		cin>>ki;
		for(int j=0;j<ki;j++){
			int aij,tij;
			cin>>aij>>tij;
			t[aij][j]=tij;
		}
	}
	//cout<<"input plan"<<endl;
	for(int r=0;r<q;r++){
		int x,y;
		cin>>x>>y;
		int time=w[x]+w[y];
		
	}
	
	return 0;
}
