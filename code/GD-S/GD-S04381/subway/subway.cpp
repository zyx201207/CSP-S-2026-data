#include <bits/stdc++.h>
using namespace std;
long long Sta[100086];
long long c,n,m,d,q;
int mapp[1005][1005],nums[1005];
long long v[1006];
int main()
{
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>Sta[i];
	}
	int k,x,y;
	for (int i=1;i<=1000;i++){
		for (int j=1;j<=1000;j++){
			mapp[i][j]=1e6;
		}
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>nums[j];
			cin>>v[nums[j]];
		}
		for (int j=1;j<=k;j++){
			for (int l=j;l<=k;l++){
				mapp[nums[j]][nums[l]]=min(mapp[nums[j]][nums[l]],v[nums[j]]+v[nums[l]]);
				mapp[nums[j]][nums[l]]=min(mapp[nums[l]][nums[j]],v[nums[j]]+v[nums[l]]);
			}
		}
	}
	for (int i=1;i<=q;i++){
		cin>>x>>q;
		
	}
	return 0;
}
