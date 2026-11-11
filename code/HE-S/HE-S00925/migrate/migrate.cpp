#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5;
int a[2*MAX+5];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}cout<<n/d<<endl;
	}
	return 0;
} 
