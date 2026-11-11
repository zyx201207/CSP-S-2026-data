#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,i,j,a[200005],ans=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		while(!(c[i]>='a'&&c[i]<='z')) scanf("%c",&c[i]);
		//printf("000\n");
	}
	i=1;j=n;
	while(i<j){
		int q=min(a[i],a[j]);
		if(c[i]==c[j]){
			a[i]-=q;
			a[j]-=q;
			if(a[i]==0) i++;
			if(a[j]==0) j--;
		}
		else{
			a[i]-=q;
			a[j]-=q;
			if(a[i]==0) i++;
			if(a[j]==0) j--;
			ans+=q;
		}
	}
	printf("%lld",ans);
	return 0;
}
