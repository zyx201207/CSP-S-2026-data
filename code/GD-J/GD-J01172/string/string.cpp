#include <iostream>
using namespace std;
struct inolong{long long a;char c;};
int main()
{
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);

	long long n;
	cin>>n;
	inolong lst[n];
	for(long long i=0;i<n;i++)
	{
		cin>>lst[i].a>>lst[i].c;
	}
	long long sum=0;
	long long l1=0,r1=n-1;
	while(!(l1>r1))
	{
		if(lst[l1].c!=lst[r1].c)
		{
			sum+=min(lst[l1].a,lst[r1].a); 
		}
		long long ls=abs(lst[l1].a-lst[r1].a);
		if(ls==0){l1++;r1--;}
		else if(lst[l1].a>lst[r1].a){lst[l1].a=ls;r1--;}
		else if(lst[l1].a<lst[r1].a){lst[r1].a=ls;l1++;}
	}
	cout<<sum<<"\n";

	fclose(stdin);fclose(stdout);
	return 0;
}
