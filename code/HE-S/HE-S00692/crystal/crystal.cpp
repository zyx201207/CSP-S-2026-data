#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int ans=0;
int amx=-1000000000000,amn=1000000000000;
inline int chk(int x){
	int mm=m;
	int ret=0;
	int pos=lower_bound(a+1,a+1+n,x)-a;
	for(int i=pos;i<=n;i++){
		if(a[i]==x)ret++;
	}
	for(int i=pos-1;i;i--){
		int cha=x-a[i];
		if(mm<cha)break;
		mm-=cha;
		ret++;
	}
	return ret;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		amx=max(a[i],amx);
		amn=min(amn,a[i]);
	}
	sort(a+1,a+1+n);
	int cha=a[2]-a[1];
	bool dc=1;
	for(int i=3;i<=n;i++){
		int cc=a[i]-a[i-1];
		if(cc!=cha){
			dc=0;
			break;
		}
	}
	if(dc){
		cout<<chk(amx);
		return 0;
	}
	int l=amn,r=amx;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])continue;
		ans=max(ans,chk(a[i]));
	}
	cout<<ans;
	return 0;	
}
