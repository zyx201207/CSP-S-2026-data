#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=1e6+10;
const int K=15;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m;
int a[N],sum[N];
int solve(int id){
//	cout<<"solve!"<<endl;
	int val=a[id];
	int p=1,pos=0;
	while(p){
		int cnt=pos+p;
		if(cnt>id-1){
			p/=2;
			continue;
		}
//		cout<<"now:"<<cnt<<endl;
//		cout<<"d:"<<a[id]*cnt-sum[id-1]+sum[id-cnt-1]<<endl;
		if(a[id]*cnt-sum[id-1]+sum[id-cnt-1]<=m){
//			cout<<"Yes!!!"<<endl;
			pos+=p;
			p*=2;
		}else{
//			cout<<"No!!!"<<endl;
			p/=2;
		}
	}
//	cout<<"return:"<<pos+1<<endl<<endl;
	return pos+1;
}
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;--i){
//		cout<<"i:"<<i<<endl;
		ans=max(ans,solve(i));
	}
	write(ans);
	return 0;
}
/*
5 5
1 2 4 8 9

4 4
1 3 4 5

5 8
-3 -1 2 2 7

*/
