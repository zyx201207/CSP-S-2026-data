 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	int n,js=0;
 	cin>>n;
 	string c="";
 	string c2;
 	for(int i=1;i<=n;i++)
 	{
 		int b;
 		cin>>b;
 		char a;
 		cin>>a;
 		for(int j=0;j<b;j++)
 		{
 			c+=a;
		}
	}
	int a=c.size();
	for(int i=a;i>0;i--)
	{
		c2[0]=c[0];
		c2+=c[i];
	}
	for(int i=0;i<=a;i++)
	{
		if(c[i]!=c2[i])
		{
			js++;
		}
	}
	cout<<js;
 	return 0;
 }
