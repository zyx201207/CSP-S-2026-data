//GZ-S00306  贵州省  遵义一中 邓卓远 
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,sum[500005],gt[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i= 0;i<n;i++)
    {
    	cin>>sum[i];
	}
	sort(sum,sum+n);
	gt[0] = 0;
	for(int i = 1;i < n;i++)
	{
		gt[i] =gt[i-1] + (sum[i] - sum[i-1]) * i;
		if(m < gt[i])
		{
			cout << i;
			return 0; 
		}
	}
	cout << n;
    return 0;	
}

