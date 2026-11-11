#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],sum,ans,t,s;
char c[200005];
ll Ceil(ll x,ll y)
{
	if(x % y == 0)return x/y;
	else return x/y+1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum += a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s += a[i];
		if(s >= Ceil(sum,2))
		{
			t = i;
			break;
		}
	}
	for(int i=1,j=n;i<=j,i<=t;)
	{
		if(a[i] > a[j])
		{
			if(c[i] != c[j])ans+=a[j];
			a[i] -=a[j];
			j--;
		 } 
		if(a[i] < a[j])
		{
			if(c[i] != c[j])ans+=a[i];
			a[j] -= a[i];
			i++; 
		}
		if(a[i] == a[j])
		{
			if(c[i] != c[j])ans+=a[j];
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
