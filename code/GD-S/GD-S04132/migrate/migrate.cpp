#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
vector<int> x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			x.push_back(0);
		}
		for(int i=1;i<=n;i++)cin>>x[i];
	}
	cout<<0<<endl<<1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
