#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long n,m,a[MAXN],ans=-1;
bool f=1,f1=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)f=0;
		if(a[i-1]-a[i-2]!=a[i]-a[i-1])f1=0;
	}
	if(f){
		ans=1;
		for(long long i=1;m>0;i++,ans++)m-=i;
	}else if(f1){
		long long cha=a[2]-a[1];
		ans=1;
		for(long long i=cha;m>0;i+=cha,ans++)m-=i;
	}else{
		long long mina=MAXN,maxa=-1*MAXN,anss=0;
		for(int i=1;i<=n;i++)mina=min(mina,a[i]);
		for(int i=1;i<=n;i++)maxa=max(maxa,a[i]);
		sort(a+1,a+n+1);
		for(long long i=mina+1;i<=maxa;i++){
			int j=1,x=m;
			while(a[j]>i){
				if(a[i]==i)anss++;
				j++;
			}
			j--;
			for(;x>0&&j>0;j--){
				if(a[j]!=i&&x>=i-a[j]){
					x-=abs(a[j]-i);
					anss++;
				}
			}
			ans=max(ans,anss);
		}
	}
	printf("%lld",ans);
	return 0;
}
