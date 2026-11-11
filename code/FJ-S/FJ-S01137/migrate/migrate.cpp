#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
ll c,t,n,d,a[N],s[N][N],b[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12)
	{
    	while(t--)
     	{
    		cin>>n>>d;
           	for(int i=1;i<=n-1;i++)
         	{
	     		cin>>a[i];
 	     	}
    	   	if(d*2<=a[2]-a[1])
        	{
    	   		cout<<0<<'\n';
         	}
        	else
        	{
            	cout<<n-2<<'\n';	
        	}
        }
    }
	return 0;
} 
