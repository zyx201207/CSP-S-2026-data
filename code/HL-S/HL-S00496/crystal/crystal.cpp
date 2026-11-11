#include<bits/stdc++.h>
using namespace std;
long long n , m , i , j , q[500005] , cha[500005] , ling=0 , deng=0;
long long cao=0 , shu=1 , da=0;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(i=1;i<=n;i++) cin >> q[i];
	
	
	sort(q+1,q+1+n);
	
	for(i=1;i<n;i++)
	{
		cha[i]=q[i+1]-q[i];
		if(cha[i]!=0)
		{
			ling=1;
		}
	}
	if(ling==0)
	{
		cout << n;
		return 0;
	}
	
	
	for(i=1;i<n-1;i++)
	{
		if(cha[i]!=cha[i+1])
		{
			deng=1;
		}
	}
	if(deng==0)
	{
		for(j=1;j<=n-1;j++)
		{
			
			cao=cao+cha[j]*shu;
			//cout << cao  << " " << shu<< '\n';
			if(cao>m)
			{
				
				break;
			}
			if(cao<=m)
			{
				shu=shu+1;
			}
		
		}
		cout << shu;
		return 0;
	}
	
	
	cao=0;
	shu=1;
	for(i=1;i<=n-1;i++)
	{
		for(j=i;j<=n-1;j++)
		{
			
			cao=cao+cha[j]*shu;
			
			if(cao>m)
			{
				
				break;
			}
			if(cao<=m)
			{
				shu=shu+1;
			}
		
		}
		da=max(da,shu);
		shu=1;
		cao=0;
	}
	cout << da;
	return 0;
}
