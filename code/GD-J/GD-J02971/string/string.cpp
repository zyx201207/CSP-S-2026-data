#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N],n,l;
char c[N];
string kkk="";
bool check(string ans,int len)
{
	for(int i=0;i<len;i++)
	{
		if(ans[i]!=ans[l-1-i]) return false;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			kkk+=c[i];
		}
	}
	if(check(kkk,l-1))
	{
		cout<<0;
		return 0;
	}
	int mid=(l-1)/2;
	int left=mid-1,right=mid+1;
	int cnt=0;
	while(1)
	{
		if(kkk[left]!=kkk[right])
		{
			break;
		}
		cnt++;
		left--,right--;
	}
	int AC=0;
	int idx=l-1; 
	for(int i=0;i<mid-cnt;i++)
	{
		if(kkk[i]!=kkk[idx]) AC++;
		idx--;
	}
	cout<<AC;
	return 0;
}
