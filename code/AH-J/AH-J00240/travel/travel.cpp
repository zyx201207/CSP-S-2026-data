#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>n>>a>>m>>b;
    if(n==m)
    {
    	cout<<1;
		if(a[0]==b[0] && a[1]==b[1])
    	{
	    	cout<<1;
	    	if((a[2]<='C' && b[2]<='C') || (a[2]>'C' && b[2]>'C'))
	    	{
	    		cout<<1;
	    		int x=a[2]-'A',y=b[2]-'A';
	    		if(abs(x-y)==1) cout<<1;
	    		else cout<<0;
			}
	    	else
	    		cout<<0<<0;
		}
    	else cout<<0<<0<<0;
	}
    else cout<<0<<0<<0<<0;
    return 0;
}
