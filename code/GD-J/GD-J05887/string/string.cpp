#include<bits/stdc++.h>
using namespace std;
long long n,a;
string s;
long long k,sum,u;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++)
		{
				s[u]=b;
				u++;
		}
		k+=a;
	} 	
	k/=2;
	if(s.size()%2==1)
		for(int i=0;i<=k;i++)
		{	
			if(s[k-i]!=s[k+i]) 
			{
				sum++;
			}
		}
	if(s.size()%2==0)
	for(int i=0;i<=k;i++)
		{	
			if(s[k-i]!=s[k-1+i]) 
			{
				sum++;
			}
		}
	cout<<sum;
	return 0;
}




