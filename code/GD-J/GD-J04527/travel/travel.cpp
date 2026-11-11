#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string aa,bb;
	cin>>a>>aa>>b>>bb;
//	cout<<a<<" "<<aa<<" "<<b<<" "<<bb;
	if(a==b)
	{
		printf("1");
		if(aa[0]==bb[0] && aa[1]==bb[1])
		{
			printf("1");
			if((aa[2]<='C' && bb[2]<='C') || (aa[2]>='D' && bb[2]>='D'))
				printf("1");
			else
				printf("0");
				
		}
		else
			printf("00");
		if(abs(aa[2]-bb[2])==1 && ((aa[2]!='C' && bb[2]!='D') && (aa[2]!='D' && bb[2]!='C')) && aa[0]==bb[0] && aa[1]==bb[1])
			printf("1");
		else
			printf("0");
	}
	else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
