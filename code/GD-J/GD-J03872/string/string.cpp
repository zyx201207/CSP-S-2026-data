#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
struct node{
	char c;
	int num;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	node l=a[1],r=a[n];
	int ll=1,rr=n,ans=0;
	while(1) {
		if(ll>=rr) break;
		if(l.num>r.num) {
			if(l.c!=r.c) ans+=r.num;
			l.num-=r.num;
			r=a[rr-1];
			rr--;
		}
		if(l.num<r.num) {
			if(l.c!=r.c) ans+=l.num;
			r.num-=l.num;
			l=a[ll+1];
			ll++;
		}
		if(l.num==r.num) {
			if(l.c!=r.c) ans+=r.num;
			l=a[ll+1],r=a[rr-1];
			ll++,rr--;
		}
	}
	cout<<ans<<"\n";
}
