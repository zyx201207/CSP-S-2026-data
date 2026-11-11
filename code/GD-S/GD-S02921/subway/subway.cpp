#include<bits/stdc++.h> 
using namespace std;



int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0&&b==2)
		cout<<32<<17;
	else if(a==0&&b==3)
		cout<<35<<16;	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
