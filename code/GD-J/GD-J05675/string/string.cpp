#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s;
void check()
{
	long long l=(s.size()+1)/2,num=0;
	string str="";
	for(int i=l-1;i>=0;i--)
	{
		str+=s[i];
		
	 } 
	 for(int i=l-1;i<s.size();i++)
	 {
	 	if(s[i]!=str[i-l+1])	 
		 {
	
		 	num++;
		 }
	 }
	 cout<<num;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		 } 
	 } 
	
	check();
	return 0;
}


