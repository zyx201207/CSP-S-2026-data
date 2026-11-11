#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
long long n,m,a[200005],k,maxx=-1,tp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	if(m==1)
	{
		cout<<a[0];
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		tp=a[k];
		for(int j=k;j<k+m-1;j++)
		{
			tp&=a[j+1];
		}
		k++;
		if(tp>maxx) maxx=tp;
	}
	cout<<maxx;
	return 0;
}
