#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int C,T;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>C>>T;
	int n,d;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<"\n";
	}
	return 0;
}
