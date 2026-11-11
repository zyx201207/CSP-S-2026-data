#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
namespace FastIO{
	inline ll read(){
		ll s=0,f=1;char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}while('0'<=c&&c<='9'){
			s=(s<<1)+(s<<3)+c-'0';
			c=getchar();
		}return s*f;
	}
}
using FastIO::read;

//shou juan:6:27
const int N = 5050;
const int inf = 0x3f3f3f3f;
int c,t;
ll n,d;
ll x[N];
//lisanhua
int nxt[N],lnxt[N];
int tmp[N],tmp2[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();ans=0;
		for(int i=1;i<=n;i++)x[i]=read();
		nxt[n]=lnxt[n]=inf;
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&x[j+1]-x[i]<=d)j++;
			nxt[i]=j;
			if(nxt[i]==i)nxt[i]=inf;
		}for(int i=n,j;i>=1;i--){
			while(j>1&&x[i]-x[j-1]<=d)j--;
			lnxt[i]=j;
			if(lnxt[i]==i)nxt[i]=-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1,flg;j<=n;j++){
				flg=0;
				int v=i;tmp[0]=0,tmp2[0]=0;
				while(nxt[v]<=j){
					tmp[++tmp[0]]=nxt[v];
					v=nxt[v];
					if(nxt[v]>j)tmp[++tmp[0]]=j;
				}
				v=j;
				while(lnxt[v]>=i){
					tmp2[++tmp2[0]]=lnxt[v];
					v=lnxt[v];
					if(lnxt[v]<i)tmp2[++tmp2[0]]=i;
				}
				for(int i=1;i<=tmp[0];i++){
					if(tmp[i]!=tmp2[tmp[0]+1-i]){
						if(abs(tmp[i]-tmp2[tmp[0]+1-i])==1&&(!flg))flg=1;
						else{
							flg=2;
							break;
						}
					}
				}if(flg==1)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	
	
	
	return 0;
}
