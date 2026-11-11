#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2100000;
int c,t,n,nxt[N],lst[N],ls[N],rs[N],ls1[N],rs1[N],ls2[N],rs2[N];
long long d,x[N],ans;
inline long long read(){
	int op=1;
	char c=getchar();
	while(!('0'<=c&&c<='9'||c=='-'))c=getchar();
	if(c=='-')op=-1,c=getchar();
	long long s=0;
	while('0'<=c&&c<='9')s=s*10+c-'0',c=getchar();
	return s*op;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		for(int i=1,p=1;i<=n;i++){
			while(p+1<=n&&x[p+1]-x[i]<=d)p++;
			nxt[i]=p;
		}
		for(int i=n,p=n;i>=1;i--){
			while(p-1>=1&&x[i]-x[p-1]<=d)p--;
			lst[i]=p;
		}
		for(int i=1;i<=n;i++)ls[i]=rs[i]=0;
		for(int i=1;i<=n;i++)if(nxt[i]!=i)ls[nxt[i]]++;
		for(int i=n;i>=1;i--)if(lst[i]!=i)rs[lst[i]]++;
		for(int i=1;i<=n;i++)if(nxt[i]!=i&&lst[nxt[i]]==i)ls[nxt[i]]+=ls[i];
		for(int i=n;i>=1;i--)if(lst[i]!=i&&nxt[lst[i]]==i)rs[lst[i]]+=rs[i];
		for(int i=1;i<=n;i++)ls1[i]=rs1[i]=0;
		for(int i=1;i<=n;i++)if(nxt[i]-i>=2)ls1[nxt[i]]++;
		for(int i=n;i>=1;i--)if(i-lst[i]>=2)rs1[lst[i]]++;
		/*for(int i=1;i<=n;i++)cout<<lst[i]<<' ';
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<nxt[i]<<' ';
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<ls[i]<<' ';
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<rs[i]<<' ';
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<ls1[i]<<' ';
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<rs1[i]<<' ';
		cout<<endl;*/
		ans=0;
		for(int i=1;i<n;i++){
			if(lst[i]!=i&&nxt[i+1]!=i+1&&nxt[lst[i]]==i+1&&lst[nxt[i+1]]==i){
				ans+=1ll*ls[lst[i]]*rs[nxt[i+1]];
			}
			if(nxt[i+1]!=i+1&&lst[nxt[i+1]]==i){
				ans+=1ll*ls1[i+1]*rs[nxt[i+1]];
			}
			if(lst[i]!=i&&nxt[lst[i]]==i+1){
				ans+=1ll*ls[lst[i]]*rs1[i];
			}
			ans+=1ll*ls1[i+1]*rs1[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
