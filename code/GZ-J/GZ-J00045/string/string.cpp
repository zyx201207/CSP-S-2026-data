//GZ-J00045 ¸¶³¿³©
#include <bits/stdc++.h>
using namespace std;
struct ff{
	long long a;
	char b;
}f[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;cin>>n;long long sum = 0;string xx = "";
	for (long long i = 1;i<=n;++i) {
		cin>>f[i].a>>f[i].b; 
		sum+=f[i].a;
		for (long long j = 1;j<=f[i].a;++j) {
		    xx+=f[i].b;
		}
	}
	long long x = 1,y = n;sum/=2;
	for (;x<y;) {
	    if (f[x].b == f[y].b) {
		    sum-=min(f[x].a,f[y].a);
		    if(f[x].a == f[y].a) {f[y].a = f[x].a = 0;++x;--y;}
		    else if (f[x].a < f[y].a) {f[y].a-=f[x].a;++x;}
		    else {f[x].a-=f[y].a;--y;}
	    }
	    else {
		    if(f[x].a == f[y].a) {f[y].a = f[x].a = 0;++x;--y;}
		    else if (f[x].a < f[y].a) {f[y].a-=f[x].a;++x;}
		    else {f[x].a-=f[y].a;--y;}
		}
	}
	if(x == y)sum-=f[x].a/2;
	cout<<sum;
    return 0;
}
