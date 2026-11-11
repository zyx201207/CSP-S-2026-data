#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[9999],a[9999][9999],t[9999][9999],qi,zhong;


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	
	
	cin>>n>>m>>d>>q;
	for (int i=0 ; i<m ; i++)cin>>w[i];
	for (int i=0 ; i<n ; i++){
		int k;
		cin>>k;
		for (int j=0 ; j<k ; j++){
			cin>>a[i][k]>>t[j][k];
		}
	}
	
	for (int o=0 ; o<q ; o++){
		cin>>qi>>zhong;
		for (int i=0 ; i<n ; i++){
			for (int j=0 ; j<n ; j++){
				if (a[0][i]==a[10][j]){
					cout<<w[i]+t[0][i]+t[1][j]+w[j]<<endl;
				}
			}
		}
		
	}
	return 0;
}
