#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 500005;
int t[N],a[N],ans[N];
int n,m;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}

	for(int i = n;i >= 1;i--)
	{
		
		if(t[a[i]]){
			for(int j = i+1;a[j] != a[i];j++)
			{
				t[a[j]] = 0;
				ans[a[j]]--;
			} 
			t[a[i]] = 0;
		}
		else
		{ ans[a[i]] = i;
			t[a[i]]=1;
		}

	}
	for(int i = 1;i <= m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
