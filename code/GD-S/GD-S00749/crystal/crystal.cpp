#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
//void write(int x){
//	if(x<0)putchar('-'),x=-x;
//	if(x<10)putchar(x+'0');
//	else write(x/10),putchar(x%10+'0');
//	return ;
//}
const int N = 5e5;
int n,m;
int a[N+7];
bool check(int x){
	int sum=0;
	deque<int>q;
	for(int i=1;i<=x+1;i++){
		if(!q.empty()){
			sum+=(a[i]-a[q.back()])*q.size();
		}
		q.push_back(i);
	}
//	printf("%lld %lld\n",x,sum);
	if(sum<=m)return true;
	for(int i=2+x;i<=n;i++){
		while(!q.empty()&&i-q.front()>x)sum-=a[i-1]-a[q.front()],q.pop_front();
		if(!q.empty())sum+=(a[i]-a[q.back()])*q.size();
		q.push_back(i);
//		printf("%lld %lld\n",i,sum);
		if(sum<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
//	printf("%lld %lld\n",n,m);
	for(int i=1;i<=n;i++)a[i]=read();
//	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	sort(a+1,a+n+1);
//	printf("%lld",check(3));return 0;
	int l=0,r=n,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
//		printf("%lld %lld %lld %lld:\n",l,r,mid,res);
		if(check(mid))l=mid+1,res=mid;
		else r=mid-1;
	}
	printf("%lld",res+1);
	return 0;
}
/*
5 8 
-3 -1 2 2 7

5 5
1 2 4 8 9


*/
