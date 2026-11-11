#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int maxn=500005;
ll a[maxn];
ll check(ll);
ll myfind(ll,ll,ll);//查找a数组当中第一个小于等于参数的下标 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll ans=0,maxi=0;
	for(ll i=a[1];i<=a[n];i++){
//		if(check(i)>ans)ans=check(i),maxi=i;
		ans=max(ans,check(i));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
ll check(ll num){
	ll ans,f=myfind(num,1,n),p,mm,i;
	for(p=f,mm=m;p>=1;p--){
		mm-=num-a[p];
		if(mm<=0)break;
	}
//	if(num==2)cout<<f<<" "<<p<<" "<<(mm>=0)<<endl;
	ans=f-p+(mm>=0)-(p==0);
	return ans;
}
ll myfind(ll num,ll c,ll r){
//	printf("I went to myfind(%d,%d,%d);\n",num,c,r);
	ll ans;
	ll mid=(c+r+1)/2;
	if(c==r)return c;
	if(a[mid]<=num)ans=myfind(num,mid,r);
	if(a[mid]>num)ans=myfind(num,c,mid-1);
	return ans;
}
