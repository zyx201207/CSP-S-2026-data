#include<bits/stdc++.h>
using namespace std;bool Mbe;
namespace MAOJUN{

typedef long long ll;
const int N=5e5+5;
int n;ll m,a[N],b[N];

inline void main(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int As=0;
	for(int i=1,j=1;i<=n;i++){
		while(a[i]*(i-j+1)-(b[i]-b[j-1])>m)j++;
		As=max(As,i-j+1);
	}
	printf("%d\n",As);
}

}bool Med;int main(){
#ifdef IO
	freopen("A/crystal1.in","r",stdin);
	freopen(".out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	MAOJUN::main();
	return 0;
}