#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ans,m;
struct node{
	ll x;
	char s;
}a[200005];
queue<node>q1;
queue<node>q2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
	}
	for(ll i=1;i<=n;i++){
		if(a[i].x>0){
			ll j=i+1;
			while(a[i].s==a[j].s){
				a[i].x+=a[j].x;
				a[j].x=0;
				j++;
			}
			q1.push(a[i]);
			m++;
		}
	}
	for(ll i=1;i<=m;i++){
		a[i].x=q1.front().x;
		a[i].s=q1.front().s;
		q1.pop();
	}
	n=m;
	ll l=1,r=n;
	while(l<r){
		if(a[l].s!=a[r].s){
			if(a[l].x<=a[r].x){
				ans+=a[l].x;
				a[r].x-=a[l].x;
				a[l].x=0;
			}
			else{
				ans+=a[r].x;
				a[l].x-=a[r].x;
				a[r].x=0;
			}
			
		}
		else{
			
			if(a[l].x<=a[r].x){
				a[r].x-=a[l].x;
				a[l].x=0;
			}
			else{
				a[l].x-=a[r].x;
				a[r].x=0;
			}
		}
		if(a[l].x==0){
			l++;
		}
		if(a[r].x==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}

