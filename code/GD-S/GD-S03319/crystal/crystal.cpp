#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],qian[500005],maxn=0;
bool cmp(long long x,long long y){
	return x<y;
}
long long er(long long l,long long r,long long rr){
	long long mid=l+(r-l)/2;
	if(l==r){
		if(l==0) return rr-l;
		return rr-l+1;
	}
	if((rr-mid)*a[rr]-qian[rr-1]+qian[max(mid-1LL,0LL)]<=m&&(rr-mid-1)*a[rr]-qian[rr-1]+qian[max(0LL,mid)]>m){
		if(mid==0) return rr-mid;
		return rr-mid+1;
	}
	if((rr-mid)*a[rr]-qian[rr-1]+qian[max(mid-1LL,0LL)]<=m) return er(l,mid,rr);
	else return er(mid+1,r,rr);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(1+a,1+a+n,cmp);
	qian[0]=0;
	for(int i=1;i<=n;i++) qian[i]=qian[i-1]+a[i];
	for(int i=1;i<=n;i++) maxn=max(maxn,er(0,i,i));
	cout<<maxn;
	return 0;
} 
//5 8 -3 -1 2 2 7
