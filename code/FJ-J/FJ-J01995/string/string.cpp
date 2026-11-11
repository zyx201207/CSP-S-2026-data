#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long sum,l;
struct node
{
	int num;
	char le;
}a[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].le;
		l+=a[i].num;
		for(int j=1;j<=a[i].num;j++)s=s+a[i].le;
	}
	for(int i=0;i<l;i++)
	{
		if(a[i].le!=a[l-i-1].le)
		{
			sum+=a[l-i-1].num;
			i+=a[l-i-1].num;
			continue;
		}
		if(s[i]!=s[l-i-1])sum++;
	}
	cout<<sum/2;
	return 0;
}
