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


 

 ll W[500500];//1b
 #define vc vector
 #define pb push_back
int I[500500][21]; //1b 0b
int T[500500][21]; //1b 0b
   int K[500500];
 vc <int> A[555];
 vc <int> B[555];
 int Isz[500500];
  int Tsz[500500];
 ll D_[555][555];//1b
 inline ll&D( int a, int b)
 {
 	if(a>b)swap(a,b);
 	return  D_[a][b];
 }
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
 //#define in(x) int x; scanf("%d",&x);
  #define in(x) int x; x=fi();

int main()
{
	DI
	w(i,550)w(k,550)
	D(i,k)=-1ull/555/555;
	DS(init)
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	in(c)
	in(n)// 地铁线路数
	in(m)//站数 
	in(d)
	in(q) 
	w1(i,n)D(i,i)=0;
	
	w1(i,m)
	{
		in(w)
	W[i]=w;
}
	
	DS(input)
	w1(i,n)
	{
		in(k);K[i]=k;
		w(l,k)
		{
			in(a)
			in(t)
			A[i].pb(a);
			B[i].pb(t);
		}
	}
	w1(i,n)
	{
		 
		w(l,K[i] )
		{
			const int& a=A[i][l];
			const int& t=B[i][l];
			
			w(g,Isz[a] )
			{
				cmin( D(i,I[a][g]),
				(ll)T[a][g]+t);
			} 
			I[a][Isz[a]++]=(i);
			T[a][Tsz[a]++]=(t);
		}
	}
//	w1(i,m)
//	{
//		w(x,Isz[i])
//		ws(y,x+1,Isz[i])
//		cmin( D(I[i][x],I[i][y]),
//				(ll)T[i][x]+T[i][y]);
//	}
	
		DS( genmap)
	w(y__,20)
	{
		bool ch=0;
		w1(x,n)//1250000000
		w1s(y,x+1,n)
		w1(z,n)
		if(z!=x)
		if(z!=y)
		{
			ll& dxy=D(x,y);
			ll nd=D(x,z)+D(z,y);
			if(dxy>nd)
			dxy=nd,ch=1; 
		}
		if(ch==0)break;
			DS( lasIT)
	}
			DS( lashen)
	w(__,q)
	{
		in(x);
		in(y);
		ll as=-1ull/10;
		ll ba,bb;
	//	if(x==y)as=0;
	//	else
		w(i,Isz[x])
		w(k,Isz[y])
		{
			ll nas= D(I[x][i],I[y][k]);
			nas+=T[x][i];
			nas+=T[y][k];
			if(nas<as)
			{
				as=nas;
				ba=I[x][i];
				bb=I[y][k];
			} 
		}
	//	pw("as=%d+%d+%d=",as,W[x],W[y]);
		as+=W[x]+W[y];
	//		pw("%d\n",as);
	//	pw("[%d,%d]",ba,bb);
		
		fo(as);
		putchar('\n');
	//	printf("%lld\n",as);
	}
		DS( find)
		
		fclose(stdin);
			fclose(stdout);
		return 0;
		
}

 

