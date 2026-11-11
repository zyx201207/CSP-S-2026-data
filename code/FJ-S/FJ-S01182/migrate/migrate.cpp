#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,nxt[N],pre[N],c1[N],c2[N];
ll d,x[N],f1[N],f2[N];
ll Read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		ll ans=0;
		for(int i=1;i<=n;i++)x[i]=Read(),c1[i]=c2[i]=1,f1[i]=f2[i]=0;
		for(int i=1,j=0;i<=n;i++){
			while(j<n&&x[j+1]-x[i]<=d)j++;
			nxt[i]=j;
		}
//		for(int i=1;i<=n;i++)printf("%d\n",nxt[i]-i);
		for(int i=n,j=n;i>=1;i--){
			while(j>1&&x[i]-x[j-1]<=d)j--;
			pre[i]=j;
		}
		for(int i=1;i<=n;i++){
			if(pre[nxt[i]]==i)c1[nxt[i]]+=c1[i];
			else c1[nxt[i]]++;
		}
		for(int i=n;i>=1;i--){
			if(nxt[pre[i]]==i)c2[pre[i]]+=c2[i];
			else c2[pre[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(nxt[i]-i>1){
				if(pre[nxt[i]]==i)f1[nxt[i]]+=c1[i];
				else f1[nxt[i]]++;
			}
			if(i-pre[i]>1){
				if(nxt[pre[i]]==i)f2[pre[i]]+=c2[i];
				else f2[pre[i]]++;
			}
		}
		for(int i=1;i<n;i++){
//			printf("%lld %lld\n",f1[i+1],f2[i]);
			ans=ans+1ll*f1[i+1]*f2[i];
		}
		printf("%lld\n",ans);
//		break;
	}
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
