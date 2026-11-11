#include <bits/stdc++.h>
using namespace std;
struct str{
	int len;
	char zm;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].zm;
		sum+=1ll*a[i].len;
	}
	sum/=2;
	int i=1,j=n;
	while(sum>0){
		int l=min(a[i].len,a[j].len);
		if(a[i].zm!=a[j].zm){
			if(sum<=l) ans+=sum;
			else ans+=1ll*l;
		}
		if(a[i].len>a[j].len){
			j--; a[i].len-=l;
		}
		else if(a[i].len<a[j].len){
			i++; a[j].len-=l;
		}
		else{
			i++; j--;
		}
		sum-=1ll*l;
	}
	printf("%lld",ans);
	return 0;
}
