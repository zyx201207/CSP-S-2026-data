#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=2*1e5+10;
ll n,ans=0;

struct stu{
	ll num;
	char c;
}a[MAXN];

inline ll f(char c){
	return c-'a'+1;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	ll l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				ans+=a[r].num;
				r--;
			}else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				ans+=a[l].num;
				l++;
			}else{
				ans+=a[l].num;
				l++;
				r--;
			}
		}else{
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				r--;
			}else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
