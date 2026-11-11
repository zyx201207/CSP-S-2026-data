#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
const int N = 2e5 + 5;
char a[N],la[N],ra[N];
lnt len[N],sum=0,lenl[N],lenr[N];
lnt l[N],r[N],ans=0,ll[N],lr[N],rl[N],rr[N];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
	cin >> len[i] >> a[i];
	l[i] = sum + 1;
	sum += len[i];
	r[i] = sum;
	}
	if(sum&1)
	{
		lnt len1 = sum/2;
	    lnt lf = 0,rf = n+1;
	    for(int i = 1; i <= n; i++)
		if(r[i]<=len1)lf=i;
		for(int i = n; i >= 1; i--)
		if(l[i]>=len1+2)rf=i;	
		for(int i = 1; i <= lf; i++)
		lenl[i]=len[i],la[i]=a[i];
		for(int i = n; i >= rf; i--)
		lenr[n-i+1]=len[i],ra[n-i+1]=a[i];
		rf = n - rf + 1;
		lnt sum1 = 0;
		for(int i = 1; i<= lf; i++)
		ll[i]=sum1+1,sum1+=lenl[i],lr[i]=sum1;
		sum1 =0;
		for(int i = 1; i<= rf; i++)	
		rl[i]=sum1+1,sum1+=lenr[i],rr[i]=sum1;
		if(lr[lf]!=len1)
		{
			lr[++lf] = len1;
			ll[lf] = lr[lf-1]+1;
			lenl[lf] = lr[lf] - ll[lf] + 1;
			la[lf] = a[lf]; 
		}
		if(rl[1]!=len1+2)
		{
			rl[++rf] = rr[rf-1]+1;
			rr[rf] = len1;
			lenr[rf] = rr[lf] - rl[lf] + 1;
			ra[rf] = a[n-rf+1]; 
		}
		lnt p = 1;
		while(p<=len1){
			lnt lt = lower_bound(ll+1,ll+lf+1,p+1)-ll-1;
			lnt rt = lower_bound(rl+1,rl+rf+1,p+1)-rl-1;			
			lnt newp = min(lr[lt],rr[rt])+1;
			if(la[lt]==ra[rt]){p = newp;continue;}
			ans += newp - p;
			p = newp;
		}
		cout << ans << "\n";
		}
		else
	{
		lnt len1 = sum/2;
	    lnt lf = 0,rf = n+1;
	    for(int i = 1; i <= n; i++)
		if(r[i]<=len1)lf=i;
		for(int i = n; i >= 1; i--)
		if(l[i]>=len1+1)rf=i;	
		for(int i = 1; i <= lf; i++)
		lenl[i]=len[i],la[i]=a[i];
		for(int i = n; i >= rf; i--)
		lenr[n-i+1]=len[i],ra[n-i+1]=a[i];
		rf = n - rf + 1;
		lnt sum1 = 0;
		for(int i = 1; i<= lf; i++)
		ll[i]=sum1+1,sum1+=lenl[i],lr[i]=sum1;
		sum1 =0;
		for(int i = 1; i<= rf; i++)	
		rl[i]=sum1+1,sum1+=lenr[i],rr[i]=sum1;
		if(lr[lf]!=len1)
		{
			lr[++lf] = len1;
			ll[lf] = lr[lf-1]+1;
			lenl[lf] = lr[lf] - ll[lf] + 1;
			la[lf] = a[lf]; 
		}
		if(rl[1]!=len1+1)
		{
			rl[++rf] = rr[rf-1]+1;
			rr[rf] = len1;
			lenr[rf] = rr[lf] - rl[lf] + 1;
			ra[rf] = a[n-rf+1]; 
		}
		lnt p = 1;
		while(p<=len1){
			lnt lt = lower_bound(ll+1,ll+lf+1,p+1)-ll-1;
			lnt rt = lower_bound(rl+1,rl+rf+1,p+1)-rl-1;			
			lnt newp = min(lr[lt],rr[rt])+1;
			if(la[lt]==ra[rt]){p = newp;continue;}
			ans += newp - p;
			p = newp;
		}
		cout << ans << "\n";
		}
		return 0;
	} 	
