#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

const int N=2e5,L=30;

int n,m;
int a[N+1];

vector<int> lst,now;
int ans;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],lst.emplace_back(a[i]);
	
	for(int i=L;i>=0;i--)
	{
		now.clear();
		
		int cnt=0;
		for(int p:lst)
			if(p&(1<<i)) now.emplace_back(p),cnt++;
		
		if(cnt<m) continue;
		ans|=(1<<i),lst=now;
	}
	
	cout<<ans;
	
	return 0;
}

