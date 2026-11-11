//褚哲宇 贵阳市第一中学 GZ-S00447 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=1;
	long long n,m;
	cin>>n>>m;
	long long cry[n];
	for(long long i=0;i<n;++i)
	{
		cin>>cry[i];
	}
	sort(cry,cry+n);
	long long l,r;
	l=0;
	r=1;
	long long add=0;
	long long needm=0;
	for( ;r<n;++r)
	{
		add+=(cry[r]-cry[r-1]);
		needm+=(cry[r]-cry[r-1])*(r-l);
		while(needm>m)
		{
			needm-=add;
			add-=(cry[l+1]-cry[l]);
			++l;
		} 
		if(ans<(r-l+1))
		{
			ans=r-l+1;
		}
		//cout<<l<<' '<<r<<' '<<needm<<' '<<add<<endl;
	}
	cout<<ans;
	return 0;
}
