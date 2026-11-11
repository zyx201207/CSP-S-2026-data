#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,ans=0,maxx=-1000000000001,minn=1000000000001;
int n;
bool cmp(long long a,long long b){
	return a<b;
}
long long check(long long x){
	long long res=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=x){
			return res;
		}
		res+=(x-a[i]);	
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn) minn=a[i];
		if(a[i]>maxx) maxx=a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long le=minn-1,ri=maxx+1,mid;
	while(le+1!=ri){
		mid=le+(ri-le)/2;
		if(check(mid)>m) ri=mid;
		else{
			le=mid;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=le) ans++;
	}
	cout<<ans;
	return 0;
}
