#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,ans=0;
	string a,k;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>m>>a;
		for(int j = 0;j < m;j++)
		{
			k+=a;
		}
	}
    
    long long l;
    l = k.length()/2;
    
    long long x,y;
    for(int i = 0;i < l;i++)
    {
    	x=k[i];
    	y=k[k.length()-i-1];
    	if(x==y){continue;}
    	else{ans++;}
	}
	cout<<ans;
}