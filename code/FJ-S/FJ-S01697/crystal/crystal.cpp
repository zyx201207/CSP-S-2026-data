#include"bits/stdc++.h"
using namespace std;
using ll=long long;
#define w(i,n) for(ll i=0;i<n;i++)
#define w1(i,n) for(ll i=1;i<=n;i++)
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)

#ifndef LCS
#define printf(...)  
#endif 
ll S[500500];
ll A[500500];
template<typename L>
ll bs(ll l,ll r,L c)
{
	/*
	for(ll i=l;i<=r;i++)
	{
		if(c(i)==false)return i;
	}
	return r;*/
	
	while(l<r)
	{
		ll m=(l+r)/2;
		if(c(m)) l=m+1;
		else r=m;
	}
	return l;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	int n,m;
	cin>>n>>m; 
	w1(i,n){
	
	cin>>A[i];

	}
		sort(A+1,A+n+1);
	w1(i,n){
	S[i]=S[i-1]+A[i];
//		w(k,A[i])
//		printf("-");
//			printf("\n");		
	}

	
	ll as=0;
	w1(i,n)
	{
		ll k= bs(1,i,[&](ll x)
		 {
		 	ll tm=A[i]*(i-x+1)-(S[i]-S[x-1]) ;
		 	bool rt=tm> m;
		 	//printf("[%lld,%lld]:%d ->/%d/ %d\n",x,i,tm,i-x+1,rt);
		 	return rt;
		 });
		 cmax(as,i-k+1);
	}
	cout<<as;
	
			fclose(stdin);
			fclose(stdout);
		return 0;
}

/*

---==
  -==
   --
   --
   --------
-
--
----
----
-------
---------
---------




*/


