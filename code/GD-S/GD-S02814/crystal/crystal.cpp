#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+10;
ll n,m;
ll a[N],mx=-2000000000000,len=1,l=1,now,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	mx=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]==mx){
			len++;
		}
		else if(a[i]>mx){
			ll num=a[i]-mx;
			ll sum=len*num;
			now+=sum;
			mx=a[i];
			len++;
		}
		while(now>m){
			ll num=mx-a[l];
			now-=num;
			l++;
			len--;
		}
		ans=max(ans,len);
	}
	cout <<ans;
	return 0;
	//-2 -1 1 2 3
}
