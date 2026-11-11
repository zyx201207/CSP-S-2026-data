#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
struct Node{
	ll nu;
	char c;
};
Node a[200005];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].nu>>a[i].c;
	}
	ll l=1,r=n;//从外向里 
	while(l<r){ 
		if(a[l].nu==a[r].nu){//如：2a1b2c->aabcc，可以一下把aa换成cc，反之亦可 
			if(a[l].c!=a[r].c){
				ans+=a[l].nu;
			}
			l++;
			r--;//一起向中间走，因为左右两边都已经成回文了 
		}else if(a[l].nu>a[r].nu){//如：2a1b1c->aabc，可以把一个a换成c，反之亦可 
			if(a[l].c!=a[r].c){
				ans+=a[r].nu;//换少的（因为最多就只能换少的组的长度 
			}a[l].nu-=a[r].nu;
			r--;//换完了，向左走 
		}else {//上一个倒过来 
			if(a[l].c!=a[r].c){
				ans+=a[l].nu;
			}a[r].nu-=a[l].nu;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
//此题暴力超时间超空间，需找规律，但不知道我这个规律会不会超时，目前看是对的 
