#include<iostream>

using namespace std;

int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
//	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t>>t;
	int n,tmp;
	while(t--){
		cin>>n>>tmp;
		for(int i=1;i<=n;i++) cin>>tmp;
		cout<<n<<endl;
	}
	return 0;
}
/*
while(1) rp++;
dzd nb
give me 200pts plz
*/
