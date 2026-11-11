#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
LL cnt=1;
LL n,m;
LL a[N],b[N];
LL ans=1;
LL f(LL h,LL m){
	LL x=0;
	LL flag=1,cnt=1;
	for(int j=h;j<n;j++) 
	{
		for(int i=1;i<=flag;i++) x+=b[j];
		flag++;
		if(x>m||(n-h)<ans) return ans;
		if(x<=m){
		 cnt++;
		ans=max(cnt,ans);
	}
	}
}
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) {
	b[i]=a[i+1]-a[i];
}
	if(m==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]) cnt++;
			else cnt=1;
			ans=max(ans,cnt);
		}
		cout << ans;
		return 0; 
	}
	for(LL i=1;i<n;i++){
		ans=max(f(i,m),ans);
	}
	cout << ans;
	return 0;
} 
