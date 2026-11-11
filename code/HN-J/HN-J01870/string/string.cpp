#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0,l[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	l[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&l[i],&c[i]);
		l[i]+=l[i-1];
	}
	int left=1,right=n;
	long long lc=0,rc=l[n],disl;
	while(right>left){
		if(l[left]-lc>rc-l[right-1]){
			disl=rc-l[right-1];
			if(c[left]!=c[right])ans+=disl;
			lc+=disl,rc-=disl,right-=1;
		}else{
			disl=l[left]-lc;
			if(c[left]!=c[right])ans+=disl;
			if(l[left]-lc==rc-l[right-1])right-=1;
			lc+=disl,rc-=disl,left+=1;
		}
	}
	cout<<ans;
	return 0;
}
