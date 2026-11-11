#include<bits/stdc++.h>
using namespace std;
string a;
long long n,x[100005],s,s1,l,c,c1,ans,v;
char z[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>z[i];
		s+=x[i];
	}
	if(s%2==1)s1=s/2+1,v=1;
	else s1=s/2;
	for(int i=1;i<=n;i++)
	{
		if(s1-x[i]<=0&&v==1)
			x[i]--,v=0;
		if(s1-x[i]<=0){
			l=i;break;
		}
		s1-=x[i];
	}
	s1=x[l]-s1;
	if(s1>x[l]-s1)c=l,c1=l+1;
	if(s1<x[l]-s1)c=l-1,c1=l;
	if(s1==x[l]-s1)c=l-1,c1=l+1;
	x[l]=abs(x[l]-s1);
	for(int i=c,j=c1;i>=1,j<=n;)
	{
		if(z[i]!=z[j])ans+=min(x[i],x[j]);
		long long k=min(x[i],x[j]);
		x[i]-=k,x[j]-=k;
		if(x[i]==0)i--;
		else j++;
	}
	cout<<ans;
	return 0;
}
