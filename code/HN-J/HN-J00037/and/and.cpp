#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],minx=1e9,sum;
string s[N];
bool f;
int two_cheng(int a) {
	int x=0;
	while(a) {
		a/=2;
		x++;
	}
	return x;
}
int two_fang(int a) {
	int x=1;
	for(int i=1; i<=a; i++) {
		x*=2;
	}
	return x;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1; i<=m; i++) {
		int x=two_cheng(a[i]);
		int c=a[i];
		for(int j=1; j<=x; j++) {
			s[i][j]=c%2;
			c/=2;
		}
		minx=min(minx,x);
	}
	for(int j=1; j<=minx; j++) {
		int x=int(s[1][j]);
		int y=two_fang(j);
		f=0;
		for(int i=1; i<=m; i++) {
			if(s[i][j]!=x) {
				f=1;
			}
		}
		if(f==0){
			sum+=x*y;
		}
	}
	cout<<sum/2;
	return 0;
}
