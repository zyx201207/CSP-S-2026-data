#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5; 
int n,m,a[N],pos[M],len=0,qu[M],cnt[M];
bool inqu[M],flagA;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(!(a[i]>=a[i-1])) flagA=true;
	}
	if(flagA==false){
		for(int i=1;i<=n;i++)
			if(a[i]>a[i-1]) cnt[a[i-1]]=i-1;
		cnt[a[n]]=n;
		for(int i=1;i<=m;i++) printf("%lld ",cnt[i]);
		return 0;
	}
	for(int cas=1;cas<=n;cas++){
		len=0;
		for(int i=1;i<=m;i++) inqu[i]=false;
		for(int i=cas;i<=n;i++){
			if(inqu[a[i]]==false){
				qu[++len]=a[i];
				pos[a[i]]=len;
				inqu[a[i]]=true;
			}
			else{
				for(int j=pos[a[i]]+1;j<=len;j++) inqu[qu[j]]=false;
				len=pos[a[i]];
			}
		}
		for(int i=1;i<=len;i++) cnt[qu[i]]++;
	} 
	for(int i=1;i<=m;i++) printf("%lld ",cnt[i]);
	return 0;
}
/*
11：37 a.m.打暴力看错题了……
还有时间 

11：49 a.m 搞定了，加了个性质 A 特判 
*/
