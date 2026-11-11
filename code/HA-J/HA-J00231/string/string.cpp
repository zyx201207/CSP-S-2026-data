#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll a;
	char c;
}a[200005];
ll n,ans=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		cnt+=a[i].a;
	}
	ll cnt_l=1,cnt_r=cnt;
	for(ll l=1,r=n;cnt_l<=cnt_r&&l!=r;){
		if(a[l].a==a[r].a){
			if(a[l].c!=a[r].c){
				ans+=a[l].a;
			}
			cnt_l+=a[l].a;
			cnt_r-=a[r].a;
			l++;
			r--;
		}else if(a[l].a>a[r].a){
			if(a[l].c!=a[r].c){
				ans+=a[r].a;
			}
			a[l].a-=a[r].a;
			cnt_l+=a[r].a;
			cnt_r-=a[r].a;
			r--;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[l].a;
			}
			a[r].a-=a[l].a;
			cnt_l+=a[l].a;
			cnt_r-=a[l].a;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
