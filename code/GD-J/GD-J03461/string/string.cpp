#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll sum,n,s,l=1,r,c,d;
struct node{
	ll a;
	char b;
	
}ar[N],br[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>ar[i].a>>ar[i].b;
	}r=n;
	c=ar[l].a;
	d=ar[r].a;
	while(l<=r){
		if(c>d){
			if(ar[l].b!=ar[r].b)sum+=d;
			c-=d;
			r--;
			d=ar[r].a;
		}else if(c==d){
			if(ar[l].b!=ar[r].b)sum+=d;
			l++;
			r--;
			d=ar[r].a;
			c=ar[l].a;
		}else{
			if(ar[l].b!=ar[r].b)sum+=c;
			d-=c;
			l++;
			c=ar[l].a;
		}
	}cout<<sum;
	return 0;
}
