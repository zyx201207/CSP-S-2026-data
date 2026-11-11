#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=e;i++){
		cout<<i*d;
	}
	return 0;
}
