#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	srand(time(0));
	int a,b,c,d,e;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=e;i++){
		cout<<rand()%100<<"\n";
	}
	return 0;
}

