#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
pair<int,char>a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %c",&a[i].first,&a[i].second);
	for(int i=1,j=n;i<j;){
		int k=min(a[i].first,a[j].first);
		if(a[i].second!=a[j].second)ans+=k;
		a[i].first-=k;a[j].first-=k;
		if(a[i].first==0)i++;
		if(a[j].first==0)j--;
	}
	printf("%lld",ans);
	return 0;
}
