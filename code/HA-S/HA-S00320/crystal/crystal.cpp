#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
const int N = 5e5+5;
lnt n , m , a[N], sum[N];
lnt read()
{
	lnt x = 0,f = 1;
	char c = getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f*=-1;
		c = getchar();
	}
	while(c>='0'&&c<='9')
	{
		x = x * 10 + (c-'0');
		c = getchar();
	}
	return x * f;
}
void write(lnt x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	} 
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
lnt LR(int l,int r)
{
	return sum[r] - sum[l-1];
}
lnt check(lnt i,lnt k)
{
	if(k == 0)return 0;
	return a[i]*k - LR(i - k, i - 1);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
    sum[0]=0;
    for(int i = 1; i<= n; i++)
    	a[i] = read();
    sort(a+1,a+n+1); 
    for(int i = 1; i<= n; i++)
    sum[i] = sum[i-1] + a[i];
    lnt ans = 0;
    for(int i = 1; i<= n; i++)
    {
    	if(i==1)continue;
    	lnt l = 0, r = i - 1;
    	while(l<=r)
    	{	  
    		lnt mid = (l+r)/2;
    		if(m>=check(i,mid))
    		{
    			ans = max(ans , mid);
    			l = mid + 1;
    		}
    		else r = mid - 1;
    	}
    }
    write(ans+1);
    return 0;
} 
