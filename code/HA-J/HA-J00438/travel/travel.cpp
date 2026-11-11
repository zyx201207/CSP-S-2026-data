#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
//	string s;
	int t1=0,t2=0;
	for(int i=0;i<c1.size();i++) t1=t1*10+int(c1[i]-'0');
	for(int i=0;i<c2.size();i++) t2=t2*10+int(c2[i]-'0');
//	cout<<t1<<" "<<t2;
	if(t1==t2)
	{
		int a=0,b=0;
		for(int i=0;i<s1.size()-1;i++) a=a*10+int(s1[i]-'0');
		for(int i=0;i<s2.size()-1;i++) b=b*10+int(s2[i]-'0');
//		cout<<a<<" "<<b<<endl;
		if(a==b)
		{
			char x=s1[2],y=s2[2];
			if((x<='C'&&y<='C')||(x>'C'&&y>'C'))
			{
				if(x=='A'&&y=='B') cout<<"1111";
				else if(x=='B'&&y=='C') cout<<"1111";
				else if(x=='B'&&y=='A') cout<<"1111";
				else if(x=='C'&&y=='B') cout<<"1111";
				else if(x=='D'&&y=='F') cout<<"1111";
				else if(x=='F'&&y=='D') cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

