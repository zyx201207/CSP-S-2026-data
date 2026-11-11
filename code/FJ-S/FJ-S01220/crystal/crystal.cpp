#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MX=5*1e5+50;
ll a[MX];
ll n,m;
ll tmp_he;
ll tmp_cha;
int cnt_mx;
ll ans[MX];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ans[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]+a[i];
	}
	int l=1;
	int r=1;
	int cnt=1;
	while(r<=n){
		tmp_he=ans[r+1]-ans[l-1];
		tmp_cha=a[r+1]*(cnt+1)-tmp_he;
		if(tmp_cha<=m){
		    r++;
		    cnt++;
		}else{
			l++;
			cnt--;	
		}
		cnt_mx=max(cnt,cnt_mx);
	}
	cout<<cnt_mx;
	return 0;
} 
