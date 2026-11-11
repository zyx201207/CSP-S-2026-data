#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],ans;
int cnt[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int st=1,cost=0;
	for(int i=1;i<=n;i++){
		int len=i-st;
		cost+=len*(a[i]-a[i-1]);
		while(cost>m){
			cost-=a[i]-a[st];
			st++;
		}
		ans=max(ans,i-st+1);
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Wow,it is quite easy!
