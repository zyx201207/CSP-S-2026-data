#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		t--;
		cout<<t<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
