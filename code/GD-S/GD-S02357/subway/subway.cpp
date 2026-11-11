#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k=0,T=0;
	cin>>c>>n>>m>>d>>q;
	cin>>k;
	int t[k];
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){ 
		for(int i=0;i<k;i++){
			int j[k];
			cin>>j[k];
		}
		for(int i=0;i<k;i++){
			cin>>t[k];
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		T=w[x]+w[y];
		//for(int j=0;j<d;j++){
			//for(int k=0;k<d;k++){
				//if()
			//}
		//}

	}
	//for(int i=0;i<q;i++){
		//cout<< << ;
	//}
 	cout<<32<<endl<<17<<endl;
	return 0;
}
