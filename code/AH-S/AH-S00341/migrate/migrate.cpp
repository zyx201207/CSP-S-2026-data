#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(NULL));
	cin>>c>>t;
	while(t--){
		cout<<rand()%t<<"\n";
	}
	return 0;
}
//freopen("migrate.in","r",stdin);
//wo xiang shang mi huo xing wei da shang
