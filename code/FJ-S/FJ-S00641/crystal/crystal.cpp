#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,mx=-1,q[N],h=1,t=1;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f = -f;
		c = getchar();
	}
	while(isdigit(c)){
		x = (x<<3)+(x<<1)+(c^48);
		c = getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();
	m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	sort(a+1,a+n+1);
	a[0] = a[1];
	for(int i=1;i<=n;i++){
		q[t] = i;
		ans += (t-h)*(a[i]-a[i-1]);
		t++;
		while(ans>m){
			ans -= a[t-1]-a[h];
			h++;
		}
		mx = max(mx,t-h);
	}
	cout << mx;
	return 0;
}
