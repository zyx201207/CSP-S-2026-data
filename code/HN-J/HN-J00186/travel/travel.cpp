#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2)
	{
		ans+="1";
	}//同车厢 
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	string p1=s1.substr(0,2),p2=s2.substr(0,2);
	if(p1==p2)//同排 
	{
		ans+="1";
		char zw1=s1[2],zw2=s2[2];
		if((zw1=='A'||zw1=='B'||zw1=='C')&&(zw2=='A'||zw2=='B'||zw2=='C'))//都在ABC座 
		{
			ans+="1";
		}
		else if((zw1=='E'&&zw2=='F')||(zw1=='F'&&zw2=='E'))//在ef座，可以证明是相邻 
		{
			ans+="11";
			cout<<ans<<endl;
			return 0;
		}
		else
		{
			ans+="00";
			cout<<ans<<endl;
			return 0;			
		}
		
		if(abs((int)(zw2-zw1))==1) ans+="1";
		else ans+="0";
	}
	else ans+="000";
	cout<<ans<<endl;
	return 0;
}

