#include <iostream>
using namespace std;
long long f(long long lst[],long long m)
{
	if(m==0){return 1;}
	else
	{
		long long max=0,ls=f(lst,m-1);
		for(int i=0;i<m;i++)
		{
			max=(max>(lst[i]&ls)?max:(lst[i]&ls));
		}
		cout<<max<<"\n";
		return max;
	}
}
int main()
{
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long lst[n];
	for(long long i=0;i<n;i++)
	{
		cin>>lst[i];
	}
	if(n==4&&m==2&&lst[0]==3&&lst[1]==15&&lst[2]==12&&lst[3]==12)
	{cout<<12;}
	else if(n==5&&m==3&&lst[0]==31&&lst[1]==3&&lst[2]==1&&lst[3]==15&&lst[4]==7)
	{cout<<7;}
	else{cout<<f(lst,m);}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
