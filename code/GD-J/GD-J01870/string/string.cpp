#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define debug(x) freopen(x".in","r",stdin);freopen("debug.txt","w",stdout);
using namespace std;
typedef long long ll;
struct st {
	ll len;
	char c;
} a[200010],b[200010];
ll n,len=0,ans,p=0;
stack<st>zl;
int main() {
	fre("string");
	cin>>n;
	for(int i=1; i<=n; i++) {
		ll x;
		char y;
		cin>>x>>y;
		if(a[len].c==y) {
			a[len].len+=x;
		} else {
			a[++len].len=x;
			a[len].c=y;
		}
	}
	if(len==1) {
		cout<<0<<endl;
	} else if(len==2) {
		cout<<max(a[1].len,a[2].len)-(abs(a[1].len-a[2].len))<<endl;
	}
	int l=1,r=len;
	while(l<=r) {
		if(a[l].len>a[r].len) {
			b[++p].len=a[r].len;
			a[l].len-=a[r].len;
			b[p].c=a[l].c;
			zl.push({a[r].len,a[r].c});
			r--;
		} else if(a[l].len<a[r].len) {
			b[++p].len=a[l].len;
			b[p].c=a[l].c;
			zl.push({a[l].len,a[r].c});
			a[r].len-=a[l].len;
			l++;
		} else {
			b[++p].len=a[l].len;
			b[p].c=a[l].c;
			zl.push({a[r].len,a[r].c});
			r--;
			l++;
		}
	}
	while(!zl.empty()) {
		b[++p].len=zl.top().len;
		b[p].c=zl.top().c;
		zl.pop();
	}
	for(int i=1;i<=(p+1)/2;i++){
		int x=p-i+1;
		if(b[i].c!=b[x].c)ans+=b[i].len;
	}
	cout<<ans;
	return 0;
}
