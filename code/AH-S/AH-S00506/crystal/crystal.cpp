#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[500001],mx=-1;
void Fix(ll times,ll ending,ll count){
	if(times>m){
		a[count]--;
		mx=max(mx,ending);
		return ;
	}
	ll number[202],mxx=-1;
	for(ll i=-99;i<=100;i++){
		number[a[i+100]]++;
		mxx=max(mxx,number[a[i]+100]);
	}
	for(ll i=1;i<=n;i++){
		a[i]++;
		Fix(i+1,max(mxx,ending),i);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	Fix(0,0,1);
	cout<<mx;
	return 0;
}
