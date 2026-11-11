#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
string S;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) S+=c;
	}/*
	for(int i=0;i<S.size()/2;i++)
	{
		for(int j=S.size()-1;j>S.size()/2;j--)	
		{
			if(S[i]!=S[j]) 
			{
				cout<<i<<' '<<j<<endl;
			}//sum++;
		}
	}*/
	int j=0,k=S.size()-1;
	for(int i=0;i<S.size()/2;i++)
	{
		
		if(S[j]!=S[k]) sum++;
		//cout<<j<<' '<<k<<endl;
		if(k>S.size()/2 && j<S.size()/2) 
		{
			j++;
			k--;
		}
	}
	cout<<sum;
	//cout<<S;
	return 0;
} 
