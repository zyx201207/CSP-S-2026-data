#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N]={0},b[N]={0};
long long f(long long x){
	memset(b,0,sizeof(b));
	long long tgt=x;
	for(int i=1;i<=n;i++){
		b[i]=tgt-a[i];
	}
	sort(b+1,b+1+n);
	long long sum=0,cnt=0;
	bool flag=0;
	for(int i=1;i<=n;i++){
		if(b[i]<0) continue;
		sum+=b[i];
		cnt++;
		if(sum>m){
			flag=1;
			break;
		}
	}
	if(flag==0) return cnt;
	else return cnt-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long mx=0;
	for(int i=1;i<=n;i++){
		long long t=f(a[i]);
		mx=max(mx,t);
	}
	cout<<mx;
	return 0;
}
