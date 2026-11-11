#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],c[N];
long long cnt=1;
int k=1,t,p;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	cnt=(1<<1)-1;
	while(cnt<a[1]){
		k++;
		cnt=(1<<k)-1;
	}
	t=k;
	for(int i=1;i<=n;i++){
		if(a[i]==(1<<t)-1){
			p++;
			c[p]=a[i];
			a[i]=0;
			t--;
		}
	}
	if(p<m){
		sort(a+1,a+n+1,greater<int>());
		int y=1;
		while(p<m){
			p++;
			c[p]=a[y];
			y++;
		}
	}
	sort(c+1,c+m+1,greater<int>());
	ans=c[1];
	for(int i=1;i<=m;i++){
		ans&=c[i];
	}
	printf("%lld\n",ans);
	return 0;
}
