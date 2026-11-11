#include<iostream>
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	return 0;
}
