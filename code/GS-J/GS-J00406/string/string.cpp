 #include<bits/stdc++.h> 
using namespace std;
int a[100000000];
string b[100000000];
char c[10000000000];
string s;
int main()
{
//     freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout); 
	int n;
	int r=0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1; j<=a[i]; j++)
	   {
		   s=s+b[i];
	   } 
	}
	cout<<"0";
	for(int i=0; i<=s.size(); i++) 
	{
		c[i]=s[i];
		cout<<c[i];
	}
	cout<<" ";
	
	return 0;
}
