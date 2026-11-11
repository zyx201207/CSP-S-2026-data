#include <bits/stdc++.h>
using namespace std;
long long n,m,t,x,num,ans;
vector<int> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		a.push_back(b[i]);
	}
	
	sort(a.begin(),a.end());
	x<=n;
	for(int i=0;i<=x;i++)
	{
		t=abs(a[x]-a[i]);
		num+=t;
		if(num==m) 
		{
			ans=x+1;
			continue;
		}
		if(num>m) 
		{
			ans=x;
			continue; 
		}
		
	}
	cout<<ans<<endl;
	return 0;
	
	
	
}
