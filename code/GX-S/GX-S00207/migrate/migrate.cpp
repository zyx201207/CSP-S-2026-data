#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,dif[N],ans;
inline bool check(int l,int r,int k){
	vector<int> res;
	for(int i=l,j=l+1;i<=r;++i){
		int cnt=dif[i];
		while(cnt<k){
			cnt+=dif[j++];
		}
		if(cnt==k){
			res.push_back(j-i);
		}else{
			res.push_back(j-i-1);
		}
	}
	int len=res.size();
	for(int i=0;i<len/2;++i){
		if(res[i]==res[len-i-1]){
			return false;
		}
	}
	return true;
}
int k;
inline void calc(){
	for(int i=2;i<2*(n-1);++i){
		int mid=i,p=1,m=dif[i],d=0;
		while(mid-p>0 and mid+p<2*(n-1) and dif[mid-p]==dif[mid+p]) ++p,m=max(m,max(dif[mid-p],dif[mid+p])),d=d+dif[mid-p]+dif[mid+p];
		int len=p-1,l=mid-len,r=mid+len;
		if(k<m) continue;
		if(check(l,r,k)){
			if(k-m<m) continue;
			if(check(l,r,k-m)) ++ans;
		}
	}
}
inline void work(){
	scanf("%lld %lld",&n,&k);
	int last;
	for(int i=1,x;i<=n;++i){
		scanf("%lld",&x);
		if(i==1){
			last=x;
			continue;
		}
		dif[i*2-3]=x-last;
		dif[i*2-2]=0;
		last=x;
	}
	for(int i=1;i<=2*(n-1);++i){
		printf("%lld ",dif[i]);
	}
	//calc();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&T);
	while(T--){
		work();
	}
	return 0;
}
