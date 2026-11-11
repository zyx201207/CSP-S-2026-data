#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string aa,bb;
	cin>>a>>aa>>b>>bb;
	int c=0;
	if(a!="01"&&a!="16"&&b!="01"&&b!="16")
	{
		if(a==b)
		{
			cout<<1;
			c=1;
		}
		else
			cout<<0;
		if(aa[0]==bb[0]&&aa[1]==bb[1]&&c==1){
			cout<<1;
		}
		else{
			c=0;
			cout<<0;
		}
		if((aa[2]-'A'<=2&&bb[2]-'A'<=2&&c==1)||(aa[2]-'A'>=3&&bb[2]-'A'>=3&&c==1))
			cout<<1;
		else{
			cout<<0;
			c=0;
		}
		if((aa[2]-'A'-1==bb[2]-'A'&&c==1)||(aa[2]-'A'+1==bb[2]-'A'&&c==1))
		
			cout<<1;
		else
			cout<<0;
	}
	fflush(stdout);
	return 0;
}
