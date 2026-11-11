#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	cin>>c>>t;
	while(t--){
		cout<<rand() % 2000000000000<<endl;
	}
	return 0;
}
