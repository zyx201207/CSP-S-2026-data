#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mx,ll,f;
void fun(int x,int cur,int d){
	if(f) return;
	if(d==m+1){
		mx=max(mx,cur);
		if(mx>=ll) f=1;
		return;
	}
	for(int i=x;i<=n;i++){
		if(cur&a[i]<=mx)continue;
		fun(i+1,cur&a[i],d+1);
	}
}
bool check(int x){
	int p=lower_bound(a+1,a+n+1,x)-a;
	if(n-p+1<m)return false;
	else{
		mx=f=0;
		ll=x;
		fun(p,a[p],1);
		if(mx>=x) return true;
		else return false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	else if(n<45||n>=45&&n<500&&m<=10||n>=500&&m<=4){
		sort(a+1,a+n+1);
		int l=0,r=a[n],mid;
		while(l+1<r){
			mid=(l+r)>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		if(check(r)) cout<<r;
		else cout<<l;
	}
	else{
		sort(a+1,a+n+1);
		int sum=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			sum&=a[i];
		}
		cout<<sum;
	}
	return 0;
}

