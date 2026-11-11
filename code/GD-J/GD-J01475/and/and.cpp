#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;int n,m,ans,a[N];
void dfs(int i,int cnt,int yu_sum){
	if(i==n){
		if(cnt==m) ans=max(ans,yu_sum);
		return;
	}
	if(cnt==m){ans=max(ans,yu_sum);return;}
	dfs(i+1,cnt,yu_sum);
	if(yu_sum==0&&cnt<=1) yu_sum=a[i];
	else yu_sum&=a[i];
	dfs(i+1,cnt+1,yu_sum);
}
int qpow(int aa,int bb){
	int res=1;
	while(bb){
		if(bb&1) res*=aa;
		aa*=aa;
		bb>>=1;
	}return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	if(n<=20&&m<=20){dfs(0,0,0),printf("%lld",ans);return 0;}
	sort(a,a+n,greater<int>());
	ans=a[0];
	for(int i=1;i<m;i++) ans&=a[i];
	int B=0,ii=0;
	for(int i=0;i<=20;i++) if(qpow(2,i)==n){B=1,ii=i;break;}
	if(B){
		if(a[0]-qpow(2,ii)+1>=m){
			ans=a[0];
			for(int i=1;i<m;i++) ans&=a[i];
			printf("%lld",ans);
			return 0;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]<qpow(2,ii)&&a[i]%2==1){
				if(!cnt) ans=a[i];
				else ans&=a[i];
				cnt++;
				if(cnt==m){printf("%lld",ans);return 0;}
			}
		}
	}printf("%lld",ans);return 0;
}
