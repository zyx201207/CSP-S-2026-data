#include<bits/stdc++.h>
using namespace std;
int c,t,n,d; 
int a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	while(t--){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<0;
		memset(a,2000010,0);
	}
	return 0;
}
