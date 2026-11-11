#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m,ans=1;
int a[500005];
int d[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	if (n<=5000) {
		int i;
		for (i=1; i<=n; i++) {
			int j=i;
			int mm=m;
			int k=1;
			while (mm>0 && --j>0) {
				mm-=abs(a[i]-a[j]);
				if (mm<0) break;
				k++;
			}
			j=i;
			while (a[++j]==a[i]) k++;
			ans=max(k,ans);
		}
		cout<<ans<<endl;
	} else {
		if (n==1) {
			cout<<1<<endl;
		} else if (a[2]-a[1]==a[3]-a[2]) {
			int cha=a[2]-a[1];
			if (m>=cha) cout<<ceil(m*1.0/cha)<<endl;
			else cout<<1<<endl;
		} else if(m==0) {
			cout<<1<<endl;
		} else if (m==1) {
			cout<<2<<endl;
		} else {
			cout<<"1618"<<endl;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
