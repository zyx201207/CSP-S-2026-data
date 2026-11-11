#include <iostream>
using namespace std;

int n,m;
long long a[500005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++) {
		cin>>a[i];
	}
	cout<<n<<' '<<m<<' '<<m;
	return 0;
}
