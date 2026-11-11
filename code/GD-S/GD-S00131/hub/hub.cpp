#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=500010;
int c,t,n,k,a,b,cnt,ans;
int h[N],f[N];
queue<int> q;
struct AB{
	int x,y,n;
}l[N*2];
void in(int x,int y){
	l[++cnt].x=x,l[cnt].y=y;
	l[cnt].n=h[x],h[x]=cnt;
}
int check(int s){
	int ct=0,a,b,as=0;
	for(int i=1;i<=n;i++){
		f[i]=0;
		if((s>>i-1)&1)f[i]=1,ct++;
	}
	if(ct!=k)return 1e7;//cout<<s<<endl;
	ct=0;
	for(int i=1;i<=n;i++){
		if(!f[i])continue;
		for(int j=h[i];j;j=l[j].n){
			if(f[l[j].y])ct++;
		}
	}
//	cout<<ct<<endl;
	if(ct/2<k-2)return 1e7;
	for(int i=1;i<=n;i++){
		if(f[i])q.push(i);
	}
	while(q.size()){
		a=q.front(),q.pop();
		as=max(as,f[a]);
		for(int i=h[a];i;i=l[i].n){
			b=l[i].y;
			if(f[b])continue;
			f[b]=f[a]+1,q.push(b);
		}
	}
	return as-1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k),cnt=0;
		for(int i=1;i<=n;i++)h[i]=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			in(a,b),in(b,a);
		}
		if(k==n){
			printf("0\n");
			continue;
		}
		if(c>=13&&c<=14){
			if(k>=n/2){
				printf("1\n");
			}else{
				printf("%d\n",max(2,(n/2+2-k+3)/4));
			}
			continue;
		}
		ans=1e7;
//		cout<<check(10)<<endl;
		for(int i=1;i<(1<<n);i++){//cout<<i<<endl;
			ans=min(ans,check(i));
		}
		printf("%d\n",ans);
	}
	return 0;
} 
