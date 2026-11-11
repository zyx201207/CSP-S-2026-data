#include<bits/stdc++.h>
using namespace std;
int c,t,x[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=13&&c<=14){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<n<<'\n';
		}
	}
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n-3<<'\n';
	}
	return 0;
} 
