#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	int a;
	cin>>a;
	string a1;
	cin>>a1;
	int b;
	cin>>b;
	string b1;
	cin>>b1;
	{
		string s1,s2;
		s1=a;
		s2=b;
		{
		if(a==b)
		{
		cout<<"1";
	}
		else
		{
				cout<<"0";
			}
		}
		{
		if(s1==s2)
		{
		cout<<"1";
	}
		else
		{
				cout<<"0";
	}
	return 0;
		}
	}
}

