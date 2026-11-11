#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b)
	    cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(aa[0]==bb[0]&&bb[1]==aa[1])
	    cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if('C'>=aa[2]&&'C'>=bb[2])
	    cout<<1;
	else if('C'<aa[2]&&'C'<bb[2])
	    cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(aa[2]-bb[2]==1||bb[2]-aa[2]==1)
	    cout<<1;
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}