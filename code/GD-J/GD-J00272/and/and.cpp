#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
static int read(){
	int ans=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9'){
		ans=ans*10+(ch&15);
		ch=getchar();
	}
	return ans;
}
static int len(int a){
	int cnt=log2(a);
	if ((1<<cnt)==a) return cnt;
	else return cnt+1;
}
struct data{int bit,id;} cnt[N];
int n,m,blen,ans,a[N];
static int bitcnt(int a){
	int ans=0;
	for (int i=0;i<blen;++i){
		ans+=(!(a&1))*(1<<i);
		a>>=1;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;++i){
		a[i]=read();
		blen=max(blen,len(a[i]));
		cnt[i].id=i;
	}
	for (int i=1;i<=n;++i) cnt[i].bit=bitcnt(a[i]);
	sort(cnt+1,cnt+1+n,
		[](const data &a,const data &b){
			return a.bit<b.bit;
		}
	);
	ans=a[cnt[1].id];
	for (int i=2;i<=m;++i) ans&=a[cnt[i].id];
	printf("%d",ans);
	return 0;
}
