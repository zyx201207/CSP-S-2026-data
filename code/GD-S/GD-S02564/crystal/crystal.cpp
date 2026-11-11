#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1;
	long long m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	b[0]=0;
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		//cout << b[i] << endl;
		int l=i-ans+1;
		int num=(i-l+1)/2;
		long long s=b[i]+b[l-1]-b[i-num]-b[l+num-1];
		//cout << l << " " << i << " " << s << " " << ans << endl;
		while (s<=m){
			ans=max(i-l+1,ans);
			//cout << l << " " << i << " " << s << " " << ans << endl;
			l--;
			if (l<1){
				l=1;
				break;
			}
			num=(i-l+1)/2;
			s=b[i]+b[l-1]-b[i-num]-b[l+num-1];
		}
	}
	cout << ans;
	
	return 0;
}
