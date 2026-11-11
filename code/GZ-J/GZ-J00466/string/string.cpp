//GZ-J00466 遵义市第十九中学 吴国懋
#include<bits/stdc++.h>
using namespace std;
struct hws {
	long long jg;
	char jm;
};
hws a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cs=0;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i].jg>>a[i].jm;
	int l=1,r=n;
	while(l<=r) {
		int lasc=a[l].jm,rasc=a[r].jm;
		if(lasc!=rasc) {
			cs+=min(a[l].jg,a[r].jg);
			a[l].jg-=min(a[l].jg,a[r].jg);
			a[r].jg-=min(a[l].jg,a[r].jg);
		}else{
			l++;
			r++;
		}
		if(a[l].jg==0) l++;
		if(a[r].jg==0) r--;
	}
	cout<<cs;
	return 0;
}
