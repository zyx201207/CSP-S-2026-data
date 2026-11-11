#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a=2,b=1000000000;
	unsigned long long ans=1;
	while(b>0){
		if(b&1){
			ans*=a;
		}
		b>>=1;
		a=a*a;
		a%=99679178;
		ans%=99679178;
	}
	cout<<ans;
	return 0;
}
