#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],pos[M],nxt[N],apea[M],lst[M];
bool flag=1;
int main() {
	wc("card");
	cin>>n>>m;
	for(int i=1;i<=n;i++)  {
		cin>>a[i];
		//lst[i]=pos[a[i]];
		//nxt[pos[a[i]]]=i
		pos[a[i]]=i;
		if(i>1&&a[i]<a[i-1]) flag=0;
	}
	if(flag) {
		for(int i=1;i<=m;i++) cout<<pos[i]<<' ';
		return 0; 
	}
	for(int i=1;i<=n;i++) {
		int now=i;
		while(now<=n) {
			if(lst[a[now]]!=i) {
				lst[a[now]]=i;
				apea[a[now]]++;
			}
			now=pos[a[now]]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<apea[i]<<' '; 
	return 0;
}

