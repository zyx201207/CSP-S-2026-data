#include <bits/stdc++.h>
using namespace std;
int main()
{
	//fre("string.in","r")stdin;
	//fre("string.out","w")stdout;
	int n,x;
	string a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++) 
		{
			cin>>b;
			a+=b;
		}
	}
	for(int i=a.size()-1;i>=0;i--)
	{
		for(int j=0;j<a.size();j++){
			c[j]=a[i];
		}
	}
	int sum=0;
	for(int i=0;i<a.size();i++){
		if(c[i]==a[i]){
			cout<<"0";
			return 0;
		}
		else{
			if(a[i]!=c[i]) sum++;
		}
	}
	cout<<sum;
	return 0;
}

