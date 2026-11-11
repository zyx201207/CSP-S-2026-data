#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],d[500005],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>c[i];
	sort(c+1,c+a+1);
	for(int i=1;i<=a;i++)d[i]=d[i-1]+c[i];
	long long l=1,r=1,m=c[1];
	while(r<=a&&l<=r){
		//cout<<l<<' '<<r<<' '<<(r-l+1)*c[r]-(d[r]-d[l])<<endl;
		if(b>=(r-l+1)*c[r]-(d[r]-d[l-1]))ans=max(ans,r-l+1);
		if(b>=(r-l+1)*c[r]-(d[r]-d[l-1]))r++;
		else while(b<(r-l+1)*c[r]-(d[r]-d[l-1]))l++;
		
	}
	cout<<ans<<endl;
	//for(int i=1;i<=a;i++)cout<<d[i]<<' ';
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
0 2 5 5 10
5 8
-3 -1 2 2 7
*/
