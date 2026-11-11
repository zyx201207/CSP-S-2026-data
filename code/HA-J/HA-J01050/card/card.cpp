#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>b){
			b=a;
		}
	}cout<<n<<" "<<b<<" "<<b;
	return 0;
}
