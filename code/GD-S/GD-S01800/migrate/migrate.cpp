#include<bits/stdc++.h>

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
using namespace std;

int C,T;long long N,D,mlen=INT_MAX;
long long read(){
	long long x=0,flo=1,ch=gc();
	for(;!isdigit(ch);ch=gc()){
		if(ch=='-')flo=-1;
	}
	for(;isdigit(ch);ch=gc()){
		x=x*10+(ch^48);
	}
	return x*flo;
}

int leng[2000005];
long long a[2000005];
void dfs(int now,int st,int ed,long long len){
	if(now==ed){
		leng[len]++;
		mlen=min(mlen,len);
		return;
	}
	if(len>mlen)return;
	for(int i=now+1;i<=ed;i++){
		if(abs(a[i]-a[now])<=D){
			dfs(i,st,ed,len+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();T=read();
	while(T--){
		long long ans=0,fl=0;
		N=read();D=read();
		a[1]=read();
		if(a[1]<0){
			fl=0-a[1];
			a[1]+=fl;
		}
		for(int i=2;i<=N;i++){
			a[i]=read()+fl;
		}
		for(int i=1;i<=N;i++){
			for(int j=i;j<=N;j++){
				memset(leng,0,sizeof(leng));
				mlen=INT_MAX;
				dfs(i,i,j,1);
				if(leng[mlen]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
