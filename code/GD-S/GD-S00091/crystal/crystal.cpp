#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
const LL M=2e18;
LL n,m,ans;
LL x[N],cha[N],sum[N],to[N];
bool check(LL pans){
	memset(to,LL(0),sizeof(to));
	LL mn=M;
	pans--;
	for(int i=2;i<=n;i++){
		if(i<pans+1) to[i]+=to[i-1]+cha[i]*(i-1);
		else{
			to[i]+=to[i-1]+cha[i]*pans;
			mn=min(mn,to[i]);
			to[i]-=sum[i-1];
		}
	}
	return mn<=m;
}
LL get_ans(){
	LL l=1,r=n;
	while(l<r){
		LL mid=(l-r)/2+r;
		if(check(mid)){
			ans=mid;
			l=mid;	
		}else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	sort(x+1,x+1+n);
	sum[1]=x[1];
	for(int i=2;i<=n;i++){
		cha[i]=x[i]-x[i-1];
		sum[i]=sum[i-1]+x[i];
	}
	cout<<get_ans()<<endl;
	return 0;
}
