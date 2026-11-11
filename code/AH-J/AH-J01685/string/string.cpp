#include <iostream>
using namespace std;

const int N = 1e8 + 5;
int n,x;
char c,a[N];

int main() {
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	int l=0;
	while (n--) {
		cin>>x>>c;
		while (x--) a[++l]=c;
	}
	
	int ans=0;
	for (int i=1; i<=l/2; i++)
		if (a[i]!=a[l-i+1]) ans++;
		
	cout<<ans<<endl;
	
	return 0;
}
