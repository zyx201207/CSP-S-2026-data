#include<bits/stdc++.h>
using namespace std;
int t,b[200010],l=1,r;
long long k,n,a[200010],ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%s",&n,&s[i]);
		a[i]=n;
		b[i]=s[i]-'0';
	}
	r=t;
	while(l<r){
		if(a[r]==a[l]){
			if(b[r]!=b[l])ans+=a[l];
			l++;
			r--;
		}
		if(a[r]>a[l]){
			if(b[r]!=b[l])ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[r]<a[l]){
			if(b[r]!=b[l])ans+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
