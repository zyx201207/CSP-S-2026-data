#include<iostream>
#include<string>
#include<algorithm>
#define int long long
using namespace std;
int pf[200001];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char a[200001];
	cin>>n;
	int leng=0;
	for(int i=1;i<=n;i++)
	{
		int l;
		char cr;
		cin>>l>>cr;
		pf[i]=pf[i-1]+l;
		a[i]=cr;
		leng+=l;
	}
	int len=leng/2;
	int ans=0;
	for(int i=1;i<=len;i++)
	{
		int l1=i,l2=leng-i+1;
		int idx1=lower_bound(pf+1,pf+1+n,l1)-pf;
		int idx2=lower_bound(pf+1,pf+1+n,l2)-pf;
		char c1=a[idx1];
		char c2=a[idx2];
		if(c1!=c2) ans++;
	}
	cout<<ans;
}
