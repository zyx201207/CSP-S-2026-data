 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	int a,c;
 	string b[13],d[13];
 	cin>>a;
 	for(int i= 1;i<=3;i++)
 	{
 		cin>>b[i];
	}
	cin>>c;
	for(int i= 1;i<=3;i++)
	{
	    cin>>d[i];
	}
 	if(a==c)
 	{
 		cout<<0;
	}
	else
	{
		cout<<1;
	}
	if(b[1]==d[1]&&b[2]==d[2])
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	if((b[3]=="D"&&d[3]=="F")||(b[3]=="F"&&d[3]=="D")||(b[3]=="C"&&d[3]=="B")||(b[3]=="B"&&d[3]=="A")||(b[3]=="B"&&d[3]=="C")||(b[3]=="A"&&d[3]=="B")||(b[3]=="A"&&d[3]=="C")||(b[3]=="C"&&d[3]=="A"))
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	if((b[3]=="A"&&d[3]=="C")||(b[3]=="C"&&d[3]=="A"))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
 	return 0;
 }
