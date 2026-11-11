#include<bits/stdc++.h>
using namespace std;

int a[500005],ans[300005];

void solve()
{
	for(i=0;i<n;i++)
	{
		vector<int> heap;
		for(j=i;j<n;j++)
		{
			bool find = false;
			int idx;
			for(k=0;k<heap.size();k++)
				if(heap[k] == a[j])
				{
					find = true;
					idx = k;
					break;
				}
			if(!find) heap.push_back(a[j]);
			else
			{
				vector<int> t;
				for(k=idx;i<heap.size();k++)
					t.push_back(heap[k]);
				heap.clear();
				for(k=0;k<t.size();k++)
					heap.push_back(t[k]);
				heap.push_back(a[j]);
			}
		}
		for(j=0;j<heap.size();j++)
			ans[heap[i]]++;
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<m;i++) ans[i] = i+1;
	for(i=0;i<m;i++) cout<<ans[i]<<" ";
	return 0;
}
