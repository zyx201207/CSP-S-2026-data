#include<bits/stdc++.h>
using namespace std;
int en[500005],n,m,time_num,time_en,maxx;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>en[i];
	}
	sort(en,en+n);
	int l=1,r=1;
	time_num=1;
	time_en=m;
	while(r<=n)
	{
		if(time_en>=time_num*(en[r+1]-en[r]))
		{
			r+=1;
			time_en-=time_num*(en[r]-en[r-1]);
			time_num+=1;
			if(maxx<=time_num)maxx=time_num;
		}
		else{
			time_en+=(en[r]-en[l-1]);
			time_num-=1;
			l+=1;
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
