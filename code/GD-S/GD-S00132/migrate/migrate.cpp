#include<bits/stdc++.h>
using namespace std;bool Mbe;
typedef long long ll;
const int IN=5e7;
char _i[IN],*_I=_i;
inline ll rd(){
	ll x=0;bool f=0;
	for(;*_I<0x30;_I++)f|=*_I==0x2d;
	for(;*_I>0x2f;_I++)x=(x<<1)+(x<<3)+(*_I^0x30);
	return f?-x:x;
}
namespace MAOJUN{

typedef vector<int> vi;
#define eb emplace_back
const int N=2e6+5;
int cid,n;ll d,x[N];
int L[N],R[N],vl[N],vr[N],ul[N],ur[N];

inline void slv(){
	n=rd();d=rd();
	for(int i=1;i<=n;i++)x[i]=rd();
	L[0]=R[0]=1;
	for(int i=1;i<=n;i++){
		L[i]=L[i-1];R[i]=R[i-1];
		while(x[i]-x[L[i]]>d)L[i]++;
		while(R[i]<n&&x[R[i]+1]-x[i]<=d)R[i]++;
	}
	for(int i=1,j=0;i<=n;i++){
		int k=max(j,L[i-1]-1);
		while(j+1<i&&R[j+1]<=i)j++;
		ul[i-1]=max(0,min(j,i-2)-k);
		vl[i]=max(0,j-L[i]+1);
		if(L[i]!=i&&R[L[i]]==i)vl[i]+=vl[L[i]];
	}
	for(int i=n,j=n+1;i;i--){
		int k=min(j,R[i+1]+1);
		while(j-1>i&&L[j-1]>=i)j--;
		ur[i+1]=max(0,k-max(j,i+2));
		vr[i]=max(0,R[i]-j+1);
		if(R[i]!=i&&L[R[i]]==i)vr[i]+=vr[R[i]];
	}
	ll As=0;
	for(int i=2;i+1<n;i++){
		int l=L[i],r=R[i+1];
		if(l==i||r==i+1)continue;
		int cl=ul[i],cr=ur[i+1];
		if(R[l]==i+1)cl+=vl[l];
		if(L[r]==i)cr+=vr[r];
		As+=(ll)cl*cr;
	}
	printf("%lld\n",As);
}
inline void main(){rd();for(int T=rd();T--;slv());}

}bool Med;int main(){
#ifdef IO
	freopen("C/p.in","r",stdin);
	freopen(".out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	fread(_i,1,IN,stdin);
	MAOJUN::main();
	return 0;
}