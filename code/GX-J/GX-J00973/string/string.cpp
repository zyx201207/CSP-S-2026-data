#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,tal=0;
	char c;
	string s,s2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		tal+=t;
		cin>>c;
		for(int i=0;i<t;i++)
			s.insert(s.begin(),c);
	}
	//for(int i=0;i<tal;i++)
	//{
	//	cout<<s[i];
	//}
	cout<<endl;
	for(int i=0;i<tal;i++)
	{
		s2[i]=s[tal-i-1];
		//cout<<s2[i];
	}
		
	int flag=1;
	for(int i=0;i<tal;i++)
	{
		if(s[i]!=s2[i])	
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		cout<<"0";
		
		
	
	

	return 0;
}
