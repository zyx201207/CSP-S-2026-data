#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int MAXN = 5e5+5;
int a[MAXN] = {0},pos[MAXN] = {0};

int lpos[MAXN] = {0},lq[MAXN] = {0};
set<int> st;

int ls[MAXN] = {0},le[MAXN] = {0};
int ans[MAXN] = {0};

ll read()
{
	ll res = 0;
	bool f = 0;
	char tc = getchar();
	while(tc < '0' || tc > '9')
	{
		if(tc == '-') f = 1;
		tc = getchar();
	}
	while(tc >= '0' && tc <= '9')
	{
		res = (res<<1)+(res<<3)+(tc^48);
		tc = getchar();
	}
	return f?-res:res;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n = read(),m = read();
	for(int i = 0;i < n;i++) 
	{
		a[i] = read();
		pos[a[i]] = i;
	}
	
	for(int i = 1;i <= m;i++) lpos[i] = -1;
	
	for(int i = 0;i < n;i++)
	{
		if(pos[a[i]] > i)
		{
			if(lpos[a[i]] >= 0) st.erase(lpos[a[i]]);
			
			if(st.size()) lq[i] = *(--st.end());
			else lq[i] = -1;
			
			st.insert(i);
			lpos[a[i]] = i;
		}
		else if(pos[a[i]] == i)
		{
			if(lpos[a[i]] >= 0) st.erase(lpos[a[i]]);
			
			if(st.size()) lq[i] = *(--st.end());
			else lq[i] = -1;
		}
	}
	
	
	//for(int i = 0;i < n;i++) cout<<lq[i]<<" ";
	//cout<<endl;
	
	
	for(int i = 1;i <= m;i++) ls[i] = le[i] = INT_MIN;
	
	for(int i = n-1;i >= 0;i--)
	{
		if(ls[a[i]] < -1) ls[a[i]] = lq[i],le[a[i]] = i;
		else
		{
			if(ls[a[i]] <= i)
			{
				ls[a[i]] = min(ls[a[i]],lq[i]);
				le[a[i]] = max(le[a[i]],i);
			}
			else
			{
				ans[a[i]] += le[a[i]]-ls[a[i]];
				//cout<<ls[a[i]]<<" "<<le[a[i]]<<" "<<a[i]<<endl;
				ls[a[i]] = lq[i],le[a[i]] = i;
			}
		}
	}
	
	for(int i = 1;i <= m;i++)
		if(ls[i] >= -1)
		{
			ans[i] += le[i]-ls[i];
			//cout<<ls[i]<<"/ /"<<le[i]<<"/ /"<<i<<endl;
		}
	
	for(int i = 1;i <= m;i++) 
	{
		cout<<ans[i];
		if(i < m) cout<<" ";
	}
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

12 4
1 2 3 4 2 4 2 3 1 4 2 3

4 3
1 2 1 3
*/
