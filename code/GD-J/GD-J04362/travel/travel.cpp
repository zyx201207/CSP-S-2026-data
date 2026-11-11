#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i=1;i<=4;i++)
	{
		cin>>s[i];
	}
	if (s[1]!=s[3])
	{
		cout<<0<<0<<0<<0;
		return 0;
	 } 
	 else 
	 {
	 	cout<<1;
	 	string a=s[2].substr(0,2);
	 	string b=s[4].substr(0,2);
	 	if (a!=b)
	 	{
	 		cout<<0<<0<<0;
	 		return 0;
		 }
		 else{
		 	cout<<1;
		 	char c=s[2][2];
	 		char d=s[4][2];
	 		if (c=='D'||c=='F')
	 		{
	 			if (d!='F'&&d!='D')
	 			{
	 				cout<<0<<0;
	 				return 0;
				 }
			 }
			 else if (d=='D'||d=='F')
			 {
			 	if (c!='F'&&c!='D')
			 	{
			 		cout<<0<<0;
			 		return 0;
				 }
			 }
			 else{
			 	cout<<1;
			 }
	 		if (c-d==1||d-c==1)
	 		{
	 			cout<<1;
			 }
			 else{
			 	cout<<0;
			 }
		 }
	 }
	 
	
	return 0;
}
