//准考证：GZ-S00067 姓名：张超 学校：遵义市第二十一中学 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(x,y) for(int i=x;i<y;i++)

int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ll m,n;
    ll ans=1;
	ll tmp=1;
	ll mx;
	
    mx=0; 
	
	while(scanf("%lld %lld",&n,&m)!=-1){
	{ 
	     if(n==1){cout<<ans<<endl; continue;}
    	 vector<ll> wt(n);
    	 for(ll i=0;i<n;i++)scanf("%lld",&wt[i]);
		 if(wt[0]==wt[n-1]&&wt[0]==wt[n/2]){
	     f(1,n){
	     	if(wt[i]!=wt[0])break;
		 }
		 ans==n;
		 cout<<n<<endl;
		 continue;
		 }
		 else
    	 f(1,n){
    	 	ll v=(wt[i]-wt[i-1]);
    	 	if(v>m||m<0){
    	 	  ans=max(tmp,ans);	
    	 	  tmp=1;
    	 	  m=mx;
    	 	  continue;
			}
			if(v>0)m-=tmp*v;
			if(v<0)m-=abs(v);
			if(m>=0)++tmp; 
			ans=max(tmp,ans);
		 }
		
    } 
    cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

