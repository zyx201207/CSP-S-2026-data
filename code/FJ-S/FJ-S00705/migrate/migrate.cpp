#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,c;
	cin>>c>>t;
	while(t--){
		int n,i,d;
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		srand(time(0));
		int x=abs(rand()%(n/2));
		cout<<x<<'\n';
	}	 				
	return 0;
}
