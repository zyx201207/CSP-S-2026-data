#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt,k=0,ans=(1<<30)-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=29;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++)
			if((a[j]&k)==k&&a[j]&(1<<i))cnt++;
		if(cnt==m){
			for(int j=1;j<=n;j++)
				if((a[j]&k)==k&&a[j]&(1<<i))ans&=a[j];
			printf("%d",ans);
			return 0;
		}
		else if(cnt>m)k+=1<<i;
	}
	printf("%d",k);
	return 0;
}
