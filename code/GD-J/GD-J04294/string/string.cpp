#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("string.out","w",stdout);
	
	int n,cnt=0; 
	cin>>n;
	
	string s=" ";
	for(int i=1;i<=n;i++)
	{
		int t;
		string c;
		cin>>t>>c;
		while(t--)s=s+c;
	}
	int l=s.size();
	for(int i=1;i<=l/2+1;i++){
		if(s[i]!=s[l-i])
		{
			s[i]=s[l-i];
			cnt++;
		}
	}
	cout<<cnt<<endl;
	freopen("string.in","r",stdin);
	return 0; 
}
