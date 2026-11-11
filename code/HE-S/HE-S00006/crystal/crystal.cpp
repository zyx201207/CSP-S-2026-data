#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[1000005];
ll have,choice,pos,temp,ans,cha,cnt;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		have=m;
		pos=1;
		choice=a[i];
		cnt=0;
		while(pos<=i){
			cha=choice-a[pos];
			have-=cha;
			if(have<0){
				break;
			}
			cnt++;
			pos++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
