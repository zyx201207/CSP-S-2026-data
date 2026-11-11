#include"bits/stdc++.h"
using namespace std;
using ll=long long;
#define w(i,n) for(int i=0;i<n;i++)
#define ws(i,s,n) for(int i=s;i<n;i++)
#define rw(i,n) for(int i=n;i--;)
#define w1(i,n) for(int i=1;i<=n;i++)
#define w1s(i,s,n) for(int i=s;i<=n;i++)

#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)

//#define LCS

#ifdef LCS
#define DI ll ttt=clock();
 
#define DS(name) pw(#name":%lld\n",clock()-ttt); ttt=clock();
 
 
#define pw(...) printf(__VA_ARGS__)
#else
#define DI 
 #define DS(m)
 
#define pw(...) 
#endif


  
 #define vc vector
 #define pb push_back 
 
 
 inline bool isd(const char& c){return '0'<=c&&c<='9';}
inline int fi()
{
	int r=0;
	char c;
	while(!isd(c=getchar()));
	while(isd(c))
	r=r*10+c-'0',c=getchar();
	return r;
}

inline void fo( ll i)
{
	if(i==0){ putchar('0');return;}
	char c[30];
	int cc=0;
	while(i)c[cc++]=i%10,i/=10;
	while(cc)putchar(c[--cc]+'0');
} 
  #define in(x) int x; x=fi();
ll A[2005000];
int main()
{
	DI
 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	 
	 in(c);
	 in(T)
	 while(T--)
	 {{
	 		in(n)
	 		in(d)
	 		w1(i,n)
	 		{
	 			in(x)
	 			A[i]=x;
	 		}
	 		ll s= A[2]-A[1];
	 		if(d!=s*2)
	 		{
	 			fo(0);putchar('\n');
	 			goto EEE;
	 		}
	 	 
	 			fo(n-3);putchar('\n');
	 		
	 		
	 	
	 }EEE:;}
	 
		DS( find)
		
		fclose(stdin);
		fclose(stdout);
		return 0;
		
}

 

