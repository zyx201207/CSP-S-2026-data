#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=2e5+5;
int a[N];
char c[N];
int ans;
//woc这个T2我为啥不能一眼
//考虑若拼成的串是回文，则每一段都对应相等 
//先去把T3做了/xk，这次T2>T3
//应该是个雷霆大分讨 
//【】搜狗一直改我输入法啥意思 
//过了 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int i=1,j=n,tot=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		tot+=a[i];
	}
	int llen=a[1],rlen=a[n];
	while(i<j){
		//cout<<i<<' '<<j<<'\n';
		if(llen<rlen){
			if(c[i]!=c[j])ans+=llen;
			rlen-=llen;
			llen=a[++i];
		}else if(llen>rlen){
			if(c[i]!=c[j])ans+=rlen;
			llen-=rlen;
			rlen=a[--j];
		}else{
			if(c[i]!=c[j])ans+=llen;
			llen=rlen=0;
			llen=a[++i];rlen=a[--j];
		}
	}
	cout<<ans;
	return 0;
}
