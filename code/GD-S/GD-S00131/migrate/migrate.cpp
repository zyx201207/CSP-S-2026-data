#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2000010;
int c,t,n,mx,f1[N],f2[N],f[N];
LL ans,d,a[N];
void cal(int l,int r){
	for(int i=l;i<=r;i++){
		f1[i]=f2[i]=1e6;
	}
	f1[l]=f2[r]=0;
	for(int i=l+1,j=l;i<=r;i++){
		while(j<i&&a[j]+d<a[i])j++;
		if(j!=i)f1[i]=f1[j]+1;
	}
	for(int i=r-1,j=r;i>=l;i--){
		while(j>i&&a[i]+d<a[j])j--;
		if(j!=i)f2[i]=f2[j]+1;
	}
}
int sv(int l,int r){
	f[l]=1;
	for(int i=l+1,j=l;i<=r;i++){
		f[i]=0;
		while(j<i&&a[j]+d<a[i])j++;
		for(int k=j;k<i;k++){
			if(f1[k]+f2[i]==mx-1)f[i]+=f[k];
			if(f[i]>2)return 0;
		}
	}
	if(f[r]==2)return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d),ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			d/=(a[2]-a[1]);
			if(d==0||d==1){
				printf("0\n");
				continue;
			}
			ans=max(0ll,n-2*d+1);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cal(i,j),mx=f1[j];
				if(mx<=n&&sv(i,j))ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
