#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,m,ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	vector<int> v(n+1,0);
	for(int i=1; i<=n; i++) {
		scanf("%d",&v[i]);
		if(i==1) {
			ans=v[i];
		}
		else {
			ans&=v[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
