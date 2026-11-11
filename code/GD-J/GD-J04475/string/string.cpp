
#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,num=0;
	string txt,str="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>txt;
		for(int i=1;i<=x;i++)
	    {
		    str+=txt;
	    }
	} 
	//cout<<str<<endl;
	for(int i=0;i<str.length()/2;i++)
	{
		//cout<<str[i]<<" "<<str[str.length()-1-i]<<endl;
		if(str[i]==str[str.length()-1-i])
		{
			continue;
		}
		else
		{
			num++;
		}
		//cout<<"one"<<endl;
	}
	cout<<num;
	return 0;
	
}
