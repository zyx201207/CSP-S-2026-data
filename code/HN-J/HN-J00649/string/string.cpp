#include<bits/stdc++.h>
using namespace std;
//#define debug
const int N=2e5+100;
struct node {
	int len;
	char c;
} a[N];
int n;
long long ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i].len>>a[i].c;
	int l=1,r=n;
	while(l!=r) {
		int mx,mi;
		if(a[l].len>a[r].len) {
			mx=l;
			mi=r;
		} else {
			mx=r;
			mi=l;
		}
		if(a[l].c!=a[r].c) {
			ans+=a[mi].len;
		}
		a[mx].len-=a[mi].len;
		if(mi==r)
			r--;
		else
			l++;
	}
	cout<<ans<<'\n';
}

