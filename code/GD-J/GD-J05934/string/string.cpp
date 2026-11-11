#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
#define ll long long
ll n,a[maxn],num,pos;
char b[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i]>>b[i];
		pos+=a[i];
	}
	ll li=1,ri=n;
	while(pos>1){
		ll mmin=min(a[li],a[ri]);
		a[li]-=mmin,a[ri]-=mmin;
		if (b[li]!=b[ri]) num+=mmin;
		if (a[li]==0) li++;
		if (a[ri]==0) ri--;
		pos-=2*mmin;
	}
	cout<<num;
	return 0;
} 
