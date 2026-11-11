/*
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
bool cmp(LL a,LL b){
	return a<b;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a[i]);
	}
	sort(a+1,a+1+n,cmp);
	long long dd=0;
	bool tttt=true,f=true;
	for(LL i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(tttt){
			dd=d[i];
			tttt=0;
		}
		if(dd[i]!=dd){
			f=0;
		}
	}if(f){
		LL ans1=(1+(long long)sqrt(1+(m<<3)/dd))/2;
		LL ans2=((long double)*1.0+sqrt(long double) *1.0+(long double)*8.0);
		if(ans1!=ans2) ans2--;
		return 0;		
		fclose(stdin);
		fclose(stdout);
	}
	for(int i=1;i<=n;i++){
		s1[i]=s1[i-1]+{}
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long N=1010;
LL a[N],s[N],d[N];
bool cmp(LL a,LL b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n,m;
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++){
		scanf("%lld",a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(LL i=1;i<=n;i++){
		d[i]=a[i]-a[1];
	}
	s[1]=0;
	for(int i=2;i<=n;i++){
		s[i]=(i-1)*d[i];
	}
	LL ans=1;
	LL cost=0;
	//LL num=0;
	LL cur=0;
	for(LL i=2;i<=n;i++){
		cost=cost+d[i];
		ans=i;
		cur=i;
		if(cost>=m){
			ans--;
			break;
		}
	}
	/*for(int i=cur;i<=n;i++){
		
	}
	*/
	printf("%lld\n",ans);
	/*
	while(cost<m){
		cost=cost*num+d[++num];
		num++;
		cur=a[num];
	}
	*/              
	fclose(stdin);
	fclose(stdout);
	return 0;
}
