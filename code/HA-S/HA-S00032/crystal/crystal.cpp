#include<bits/stdc++.h>
using namespace std;
int n,ans=1,c;
long long m,num;
int a[500010],b[500010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++) {
		num=0;
		if(a[i]==c) {
			ans++;
			continue;
		} else {
			for(int j=1; j<=i-1; j++) {
				b[j]=a[i]-a[i-j];
				num+=b[j];
				if(num==m) {
//				ans=max(ans,j+1);
					if(j+1>=ans) {
						c=a[i];
						ans=j+1;
					}
					break;
				} else if(num>m) {
//				ans=max(ans,j);
					if(j>=ans) {
						c=a[i];
						ans=j;
					}
					break;
				}
			}
		}
		if(num<m) {
//			ans=max(ans,i);
			if(i>=ans) {
				c=a[i];
				ans=i;
			}
		}
	}
	cout<<ans;
	return 0;
}
