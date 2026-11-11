#include<bits/stdc++.h>
using namespace std;
int main()
{   
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)cout<<"0";
	if(n==2){
	int ka,kb;
	char sa,sb;
	cin>>ka>>sa>>kb>>sb;
    if(sa==sb)cout<<"0";
    else if(ka>=kb)cout<<kb;
    else cout<<ka;
	}
	return 0;
}
