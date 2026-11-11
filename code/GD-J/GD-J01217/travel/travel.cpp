#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e3+10;
ll n,m,ans,a[N];
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>s1>>s2>>s3>>s4;
	ll co=(s1[0]-'0')*10+(s1[1]-'0'); 
	ll ct=(s3[0]-'0')*10+(s3[1]-'0');
	ll numo=(s2[0]-'0')*10+(s2[1]-'0'); 
	ll numt=(s4[0]-'0')*10+(s4[1]-'0');
	char ro=s2[2],rt=s4[2];
	if(co==ct)
	{
		cout<<"1";
		if(numo==numt)
		{
			cout<<"1";
			if(((ro=='A'||ro=='B'||ro=='C')&&(rt=='A'||rt=='B'||rt=='C'))||((ro=='D'||ro=='F')&&(rt=='D'||rt=='F')))
			{
				cout<<"1";
				if(abs(ro-rt)==1)
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		 }
		else cout<<"000";
	 }
	else cout<<"0000";
	cout<<endl;
	return 0;
}

