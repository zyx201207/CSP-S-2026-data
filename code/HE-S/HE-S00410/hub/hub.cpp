#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("hub5.in","r",stdin);
    //freopen("hub5.out","w",stdout);
    int a[100000];
    int c,t,b,n,k,w=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>n>>k;
    	for(int i=0;i<=n;i++)
    	{
    		cin>>a[i];
    		b=a[i+1]-a[i];
    		w+=b;
		}
	}
	cout<<b<<w;
	return 0;
}
