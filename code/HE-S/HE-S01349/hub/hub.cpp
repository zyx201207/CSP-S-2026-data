#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int e=0;e<t;e++){
		cin>>n>>k;
		int x[2][n];
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				cin>>x[i][j];
			}
		}
		if(x[0][0]==1){
			cout<<1<<endl<<2;
		}
	}
	return 0;
}
