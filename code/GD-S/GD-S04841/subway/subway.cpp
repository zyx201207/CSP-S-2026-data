#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d, r;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>a>>b>>c>>d>>r;
	while(c--)cin>>a;
	while(b--){
		cin>>a;
		while(a--)cin>>d>>c;
	}
	while(r--)cin>>c;
	
	return 0;
}
