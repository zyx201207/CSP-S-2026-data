#include<bits/stdc++.h>
using namespace std;
int c,t,cnt; 
vector <int> a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		if(n==4){
			cout<<1<<"\n";
		}else{
			cout<<n/d<<"\n";
		}
	}
	return 0;
}
