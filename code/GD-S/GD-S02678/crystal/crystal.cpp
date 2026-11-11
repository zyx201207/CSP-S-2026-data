#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int a[N],cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdin);	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int a1=a[0],a2=a[n-1];
	for(int i=a1+1;i<a2;i++)
	{
		int s=0;
		cnt=0;
		int t=*(upper_bound(a,a+n,i));
		for(int j=t;j>=0;j--)
		{
			if(a[i]<j) {
				s+=(i-a[j]); 	
			}
			if(s>m) break;
			cnt++;
		}
	}
	cout<<cnt+3;
}
