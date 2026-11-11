#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int k,p,a[100010];
		cin>>p>>k;
		for(int i=0;i<k;i++){
			cin>>a[i];
		}
		cout<<k-p;		
	}
	return 0;
}
