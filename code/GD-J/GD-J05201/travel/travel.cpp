#include<bits\stdc++.h>
using namespace std;
string a,s,d,f;
int i,j,k,n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>s;
	cin>>d;
	cin>>f;
	if(a==d)
	cout<<"1";
	else{
	cout<<"0000";
	return 0;
	}
	for(i=0;i<s.size()-1;i++)
	{
		m*=10;
		m+=s[i]-'0'; 
	}
	for(i=0;i<f.size()-1;i++)
	{
		n*=10;
		n+=f[i]-'0'; 
	}
	if(n==m)
	cout<<"1";
	else{
	cout<<"000";
	return 0;
	}
	if(s[s.size()-1]<='C')
	{
		if(f[f.size()-1]<='C')
		cout<<"1";
		else{
		cout<<"00";
		return 0;
		}
	}
	if(s[s.size()-1]>='D')
	{
		if(f[f.size()-1]>='D')
		cout<<"1";
		else{
		cout<<"00";
		return 0;
		}
		
	}
	if(s[s.size()-1]-f[f.size()-1]==1||s[s.size()-1]-f[f.size()-1]==-1)
	cout<<"1";
	else
	cout<<"0";
	
}
