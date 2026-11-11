#include<bits/stdc++.h>
using namespace std;
int n,o,ans1,ans2,l;
string a,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&o);
		cin>>x;
		l+=o;
		while(o--)a+=x;
	}
	for(int i=0;i<l/2;++i){
		if(a[i]!=a[l-i-1])ans1++;
	}
	for(int i=l;i>=(l+1)/2;--i){
		if(a[i]!=a[l-i-1])ans2++;
	}printf("%d %d\n",ans1,ans2);
	printf("%d",min(ans1,ans2));
	return 0;
}
