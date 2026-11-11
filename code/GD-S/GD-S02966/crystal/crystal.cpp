#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+100;
long long n,m;
long long last,now,ans;
long long a[N];
void read(long long &x){
	x=0;
	char cc=getchar();
	long long f=1;
	while(cc<'0'||cc>'9'){
		if(cc=='-')f=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		x=(x<<3)+(x<<1)+cc-'0';
		cc=getchar();
	}
	x*=f;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	ans=1;
	now=1;
	last=1;
	for(int i=2;i<=n;i++){
		while((a[i]-a[i-1])*now>m){
			now--;
			m+=(a[i-1]-a[last]);
			last++;
		}
		m-=((a[i]-a[i-1])*now);
		now++;
		ans=max(ans,now);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
