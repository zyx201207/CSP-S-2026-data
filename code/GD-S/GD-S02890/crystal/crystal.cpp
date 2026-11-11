#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,m,a[maxn],mx=-1,ans,mi=0x3f3f3f3f;
/*
struct number{
	long long le,ri;
};
number minus(number a,number b){
	long long rig=a.ri-b.ri;
}
*/
long long check(long long ch){
	long long cnt=0,ret=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=ch){
			ret++;
			cnt+=ch-a[i];
			if(cnt>m)return -1;
		}
	}
	return ret;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1)mi=a[1];
		else mi=min(mi,a[i]);
	}
	long long l=mi,r=mx;
	while(l<r){
		long long mid=(l+r)>>1,res;
		res=check(mid);
		if(res==-1){
			r=mid-1;
		}else {
			l=mid+1;
			ans=res;
		}
	}
	cout<<ans;
	return 0;
} 
