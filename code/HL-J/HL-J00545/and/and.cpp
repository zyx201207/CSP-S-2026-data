#include <bits/stdc++.h>
using namespace std;
priority_queue<int> high;
const int N=1e5;
int a[N];
int main()
{   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
    	int c;
    	cin>>c;
    	high.push(c);
	}
	sum=high.top();
	for(int i=0;i<m;i++)
	{    
	    sum=sum&high.top();
	    high.pop();
	}
	cout<<sum;
	
}

