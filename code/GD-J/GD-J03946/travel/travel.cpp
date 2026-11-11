# include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
		cout<<"1";
	else
	    cout<<"0";
	if (s1-'A'||s1-'B'||s1-'C'||s1-'D'||s1-'E'||s1-'F'==s2-'A'||s2-'B'||s2-'C'||s2-'D'||s2-'E'||s2-'F')
	    cout<<"1";
	else
	    cout<<"0";
	if (s1-'01'||s1-'02'||s1-'03'||s1-'04'||s1-'05'||s1-'06'||s1-'07'||s1-'08'||s1-'09'||s1-'10'||s1-'11'||s1-'12'||s1-'13'||s1-'14'||s1-'15'||s1-'16'||s1-'17'||s1-'18'==s2-'01'||s2-'02'||s2-'03'||s2-'04'||s2-'05'||s2-'06'||s2-'07'||s2-'08'||s2-'09'||s2-'10'||s2-'11'||s2-'12'||s2-'13'||s2-'14'||s2-'15'||s2-'16'||s2-'17'||s2-'18')
	    cout<<"1";
	else
	    cout<<"0";
	
}
