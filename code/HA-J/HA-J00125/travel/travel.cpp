#include <bits\stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1;
	cin>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1"; 
	}
	else
	{
	cout<<"0";
	}
	string a,b;
	for(int i=0;i<=1;i++){
		a+=s1[i];
		b+=s2[i];
	}
	if(a==b){
		cout<<"1"; 
	}
	else
	{
	cout<<"0";
	}

	if(s1[2]<'D') int m=1;
	else int m=2;
	if(s2[2]<'D') int n=1;
	else int n=2;
	if(m==n){
		cout<<"1";
	}
	else cout<<"0"; 
	if(m==n){
		if(s1[2]==s2[2]+1 || s1[2]==s2[2]-1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
