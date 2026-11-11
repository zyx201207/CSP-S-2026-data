#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],top=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for (int x=1,y=n;x<y;){
		if (a[x]>a[y]){
			a[x]-=a[y];
			if (c[x]!=c[y]){
				top+=a[y];
			}
			y--;
		}
		else if (a[x]<a[y]){
			a[y]-=a[x];
			if (c[x]!=c[y]){
				top+=a[x];
			}
			x++;
		}
		else{
			if (c[x]!=c[y]){
				top+=a[x];
			}
			x++;
			y--;
		}
	}
	cout<<top;
	return 0;
}
