#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=1e5+10;

int main()
{
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0; 
	}
	else cout<<1;
	int t1=(s1[0]-'0')*10+(s1[1]-'0');
	int t2=(s2[0]-'0')*10+(s2[1]-'0');
	if(t1!=t2)
	{
		cout<<"000";
		return 0; 
	}
	else cout<<1;
	char ch1=s1[2],ch2=s2[2];
	if( ((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='D'||ch2=='F'))||
		((ch1=='D'||ch1=='F')&&(ch2=='A'||ch2=='B'||ch2=='C')) )
	{
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if(abs(ch1-ch2)>1&&(ch1<'D')) cout<<0;
	else cout<<1;
	return 0;
 }
