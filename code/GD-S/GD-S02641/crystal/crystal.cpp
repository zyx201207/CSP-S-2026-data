#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int yu=m,i=1;
	if(m==0){
		int s[500005];
		for(int j=1;j<=n;j++){
			s[a[j]]++;
		}
		for(int j=1;j<=n;j++){
			ans=max(ans,s[j]);
		}
		printf("%d",ans);
		return 0;
	}
	while(1){
		if(i==n)break;
		int cha=(a[i+1]-a[i])*i;
		if(cha==0){
			ans++;
			i++;
			continue;
		}
		if(cha>yu)break;
		yu-=cha;
		ans++;
		i++;
	}
	printf("%d",ans);
	return 0;
} 
