#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	char x;
	int L,y;
	cin>>L;
	for(int i=0;i<L;i++)
	{
		cin>>y>>x;
		for(int j=1;j<=y;j++)
		S+=x;
	}
	for(int i=0;i<S.size();i++)
	{
		for(int j=S.size()-1;j>0;j--)
		{
			if(S[i]!=S[j]){
				cout<<S.size()/2;	
				return 0;
			}
		}
	}
	cout<<"0";
	return 0;
 } 
