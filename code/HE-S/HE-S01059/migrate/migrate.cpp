#include<bits/stdc++.h>
using namespace std;
int x[5000005];
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	int a=1;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		cout<<a;
		a++;
	}
	return 0;
}
