#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i <=n;i++){
		cin>>a[i];
	}
	int minn=-100000;
	for(int i=1;i <=n;i++){
		minn=max(minn,a[i]);''
	}
	cout<<minn;
	return 0;
}
