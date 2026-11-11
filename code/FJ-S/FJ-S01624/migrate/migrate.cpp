#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
int read();ll Read();
int n,lp[N],rp[N],L[N],R[N];ll res,a[N],d;
int check(int i,int j){
	return rp[i]>lp[j];}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read();int T=read();while(T--){
		n=read();d=Read();res=0;
		for(int i=1;i<=n;i++){
			a[i]=Read();
			lp[i]=rp[i]=L[i]=R[i]=0;
		}
		for(int i=1,j=1;i<=n;i++){
			while(a[i]-a[j]>d){j++;}lp[i]=j;}
		for(int i=n,j=n;i>=1;i--){
			while(a[j]-a[i]>d){j--;}rp[i]=j;}
		for(int i=n;i>=1;i--){
			if(rp[i]==i){continue;}
			int j=rp[i];
			if(rp[j]>j){
				if(!check(i,rp[j])) R[i]+=R[j];
				if(j-1>i) R[i]-=(rp[j-1]-j);
				R[i]+=rp[j]-j;
			}
		}
		for(int i=1;i<=n;i++){
			if(lp[i]==i){continue;}
			int j=lp[i];
			if(lp[j]<j){
				if(!check(lp[j],i)) L[i]+=L[j];
				if(j+1<i) L[i]-=(j-lp[j+1]);
				L[i]+=(j-lp[j]);
			}
		}
		for(int i=n;i>=1;i--){
			if(i+1>=rp[i]) continue;
			int j=rp[i];
			int l=rp[j-2]+1,r=rp[j-1];
			if(l>r) continue;
			ll lcnt=1,rcnt=r-l+1;
			if(!check(lp[i],j-1)){
				lcnt+=(L[i]+lp[lp[j-1]+1]-lp[i]);}
			if(!check(j,rp[r])){
				rcnt+=(R[r]+rp[r]-rp[rp[j]-1]);}
			res+=lcnt*rcnt;
		}printf("%lld\n",res);
	}
	return 0;
}
int read(){
	int Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}
ll Read(){
	ll Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}
