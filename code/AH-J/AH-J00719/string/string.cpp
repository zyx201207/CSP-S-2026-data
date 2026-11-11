#include <bits/stdc++.h>
#define int long long
using namespace std;
const int max_=2e5+5;
int n,s,ll[max_];
struct node{
	int l,r;
	char c;
}a[max_];
int find_p(int x){
	int lpos=upper_bound(ll+1,ll+n+1,x)-ll-1;
	return lpos;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].l=s+1;
		s+=x;
		a[i].r=s;
		cin>>a[i].c;
		ll[i]=a[i].l;
	}
	int mid=(s+1)/2,ans=0,l=mid,r=mid;
	while(1<l||r<s){
		int fl=a[find_p(l)].l,fr=a[find_p(r)].r;
		if(l==fl||r==fr){
			l--;
			r++;
			if(a[find_p(l)].c!=a[find_p(r)].c){
				ans++;
			}
			continue;
		}
		if(l-fl<=fr-r){
			int t=l;
			l=fl;
			r=2*mid-l;
			if(a[find_p(l)].c!=a[find_p(r)].c){
				ans+=(t-l);
			}
		}else{
			int t=r;
			r=fr;
			l=2*mid-r;
			if(a[find_p(l)].c!=a[find_p(r)].c){
				ans+=(r-t);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
