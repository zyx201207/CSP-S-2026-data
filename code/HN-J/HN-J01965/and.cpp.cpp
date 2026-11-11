#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m,x;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
	    cin>>x;
	    s[i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]>s[i-1])
		{
			s[i]=s[i-1];
		}
		else return 1;
	}
	cout<<s[n/2];
    return 0;
}
