#include<bits/stdc++.h>
using namespace std;
char BEGIN;
namespace hwq{
	#define ll long long
	char buf[1<<21],*_S,*_T;
	#define gc (_S==_T&&(_T=(_S=buf)+fread(buf,1,1<<21,stdin),_S==_T)?EOF:(*_S++))
	inline ll read(){ll x=0;bool f=0;char ch=gc;while(!isdigit(ch)&&ch!='-') ch=gc;if(ch=='-') f=1,ch=gc;while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=gc;return f?-x:x;}
	const int MAXN=5e5+5;
	int n;
	ll m,a[MAXN];
	int main(){
		n=read(),m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		ll sum=0;
		int ans=1;
		for(int i=1,j=1;i<=n;i++){
			sum+=a[i];
			while(a[i]*(i-j+1)-sum>m) sum-=a[j++];
			ans=max(ans,i-j+1);
		}
		printf("%d",ans);
		return 0;
	}
}
char END;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifdef XYHQ
	printf("Memory : %lld MB\n",(&BEGIN-&END)>>20);
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
#else
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
//	clock_t begin=clock();
	hwq::main();
//	clock_t end=clock();
//	cerr<<"Time : "<<((double)end-(double)begin)/1000.0<<" s"<<endl;
	return 0;
}
