#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,sum,sums,ans,q;
struct node{
	ll num;
	char x;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	q=n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].num>>a[i].x;
		sums+=a[i].num;
	}
	for(ll i=1;i<=n&&sum<=sums/2;i++){
		if(sum+a[i].num>=sums/2){
			ll p=sums/2-sum;
			while(p){
				if(a[q].num<=p){
					p-=a[q].num;
					if(a[q].x!=a[i].x) ans+=a[q].num;
					a[q].num=0;
					q--;
				}
				else{
					a[q].num-=p;
					if(a[q].x!=a[i].x) ans+=p;
					p=0;
				}
			}
			break;
		}
		sum+=a[i].num;
		while(a[i].num){
			if(a[q].num<=a[i].num){
				a[i].num-=a[q].num;
				if(a[q].x!=a[i].x) ans+=a[q].num;
				a[q].num=0;
				q--;
			}
			else{
				a[q].num-=a[i].num;
				if(a[q].x!=a[i].x) ans+=a[i].num;
				a[i].num=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
