#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,x[200005];
long long ok(long long x,long long y){
	long long as=0,bs=0,t=1,sum=0;
	bool a[35],b[35];
	while(x>0)a[++as]=x%2,x/=2;
	while(y>0)b[++bs]=y%2,y/=2;
	for(int i=1;i<=min(bs,as);i++)
		if(a[i]==b[i])sum+=t,t*=2;
		else t*=2;
	return sum;
}
bool check(long long mid){
	long long st,ch,cnt=1,pos=0;
	for(int i=1;i<=n;i++)
		if(x[i]>=mid){st=i+1,ch=i,pos=x[i];break;}
	for(int i=st;i<=n;i++){
		long long ans=ok(pos,x[i]);
		if(ans>=mid)pos=ans,cnt++;
	}
	return cnt>=m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	sort(x+1,x+1+n);
	long long l=0,r=1e9;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}


