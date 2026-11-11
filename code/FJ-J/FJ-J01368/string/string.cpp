#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
int n;
ll ans;
struct yu{
	ll shu;
	char zm;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu>>a[i].zm;
	}
	int l=1,r=n;
	while(l<r){
		ll zb=a[l].shu;
		ll yb=a[r].shu;
		if(zb==yb){
			if(a[l].zm==a[r].zm){
				l++,r--;
			}else{
				ans+=zb;
				l++,r--;
			}
		}else if(zb<yb){
			if(a[l].zm==a[r].zm){
				a[r].shu-=a[l].shu;
				l++;
			}else{
				ans+=zb;
				a[r].shu-=a[l].shu;
				l++;
			}
		}else if(yb<zb){
			if(a[l].zm==a[r].zm){
				a[l].shu-=a[r].shu;
				r--;
			}else{
				ans+=yb;
				a[l].shu-=a[r].shu;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
