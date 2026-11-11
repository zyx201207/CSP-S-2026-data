#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main()
{
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1[1]!=c3[1]){
		cout<<"0000"<<" ";
		return 0;
	}
	if(c2[1]!=c4[1])
	{
		cout<<"1000"<<" ";
		return 0;
}
	if(c2[2]<='C' && c4[2]>='D' || c4[2]<='C' && c2[2]>='D')
	{
		cout<<"1100"<<" ";
		return 0;
	}
	if(c2[2]+1 == c4[2]||c4[2]+1 == c2[2])
	{
		cout<<"1111"<<" ";
		return 0;
	}
	else{
		cout<<"1110"<<" ";
	}
	
	
	return 0;
}
