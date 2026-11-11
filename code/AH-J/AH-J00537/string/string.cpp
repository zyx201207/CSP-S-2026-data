#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;
char ch[N],tch[N];
LL n,a[N],ans,sum,ta[N];
bool ok=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		if(sum>=1e6) ok=0;else sum+=a[i];
	}
	if(ok){
		string s="";
		LL len=0;
		for(LL i=1;i<=n;i++){
			len+=a[i];
			for(LL j=1;j<=a[i];j++) s+=ch[i];
		}
		for(LL i=1;i<=len/2;i++){
			if(s[i-1]!=s[len-i]) ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	//ta[1]=a[1];tch[1]=ch[1];
	LL tot=0;
	for(LL i=1;i<=n;i++){
		if(ch[i]==ch[i-1]) ta[tot]+=a[i];
		else ta[++tot]=a[i],tch[tot]=ch[i];
	}
	LL i=1,j=tot;
	while(i<j){
		LL t=min(ta[i],ta[j]);
		ta[i]-=t;ta[j]-=t;
		if(tch[i]!=tch[j])ans+=t;
		if(ta[i]==0)i++;
		if(ta[j]==0)j--;
	}
	printf("%lld",ans);
	return 0;
}
