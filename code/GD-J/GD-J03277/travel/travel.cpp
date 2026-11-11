#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
		if((s1[2]-'A'<=2)&&(s2[2]-'A'<=2))
		{
			cout<<1;
			int t=abs((s1[2]-'A')-(s2[2]-'A'));
			if(t==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else if((s1[2]-'A'>2)&&(s2[2]-'A'>2))
		{
			cout<<11;
		}
		else
		{
			cout<<"00";
		}
	} 
	else
	{
		cout<<"000";
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
