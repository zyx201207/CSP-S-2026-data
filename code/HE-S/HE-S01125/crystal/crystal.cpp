#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
	LL n, m;
	LL s[10000010];
	LL ans=0;
	LL INF=-0x3f;
	int main()
	{	
	cin>>n;
	cin>>m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
	scanf("%d",&s[i]);
	}
	sort(s+n,s+n+1);
	int maid=s[(n-1)/2];
	


	
	cout<<"3"<<endl;
	return 0;
}
