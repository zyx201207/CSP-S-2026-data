#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {cin>>a[i]>>c[i];}
	long long ans=0;
	int x=n,i=1;
	while (i<=x) {
		if (c[i]!=c[x]) {
			if (a[i]==a[x]) {
				ans+=a[i];
				a[i]=0,a[x]=0;
				x--;
				i++;
			} else {
				if (a[i]>a[x]) {
					ans+=a[x];
					a[i]-=a[x];
					a[x]=0;
					x--;
				} else {
					ans+=a[i];
					a[x]-=a[i];
					a[i]=0;
					i++;
				}
			}
		} else {
			if (a[i]>a[x]) {
				a[i]-=a[x];
				a[x]=0;
				x--;
			} else {
				if (a[i]==a[x]) {
					a[i]=0;
					a[x]=0;
					x--,i++;
				} else {
					if (a[i]<a[x]) {
						a[x]-=a[i];
						a[i]=0;
						i++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
