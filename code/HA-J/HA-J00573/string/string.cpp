#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct calf {
	long long start,finish,len;
	char c;
} a[N];
int n,t=0;
long long tot=0LL,sum=0LL;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		long long x;
		char c1;
		cin>>x>>c1;
		if(c1!=a[t].c) {
			a[++t].c=c1;
			a[t].start=tot+1;
			a[t].finish=tot+x;
		} else a[t].finish=tot+x;
		a[t].len+=x;
		tot+=x;
	}
	int l=1,r=t;
	while(l<r) {
		if(a[l].c!=a[r].c) sum+=min(a[l].len,a[r].len);
		if(a[l].len>a[r].len) {
			a[l].len-=a[r].len;
			r--;
		} else {
			a[r].len-=a[l].len;
			l++;
		}
	}
	cout<<sum;
	return 0;
}
//Ren Boda
