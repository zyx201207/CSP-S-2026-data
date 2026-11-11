#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=5*100001;
int n,ans;
LL m,a[N];
bool sp(){
	int x=a[2]-a[1];
	for(int i=3;i<=n;i++)	if(a[i]-a[i-1]!=x)	return false;
	int cnt=1;
	for(int i=2;i<=n;i++)	if(((i-1)*i/2*x)<=m)	cnt=i;
	cout<<cnt;
	return true;
}
bool cheak(int len){
	for(int i=0;i<=n-len;i++){
		LL sum=0;
		for(int j=1;j<len;j++)
			sum+=a[i+len]-a[i+j];
		if(sum<=m)	return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(sp())	return 0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(cheak(mid)){
			ans=mid;
			l=mid+1;
		}
		else   r=mid-1;
	}
	cout<<ans;
	return 0;
}
