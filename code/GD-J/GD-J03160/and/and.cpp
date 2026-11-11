#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,maxx,a[N],k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	maxx=a[1];
	k--;
	for(int i=2;i<=n;i++)
	{
		if(k==0)continue;
		else 
		{
			maxx=(maxx&a[i]),k--;
		}
	}
	cout<<maxx;
	return 0;
}//100
