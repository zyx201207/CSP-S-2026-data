#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a,aa,b,bb,checka,checkb;
	cin>>a>>aa>>b>>bb;
	if(a==b)
	 cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	checka=aa.substr(0,2);
	checkb=bb.substr(0,2);
	if(checka==checkb)
	 cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(aa[2]<='C'&&bb[2]<='C')
	 cout<<1;
	else if(aa[2]>='D'&&bb[2]>='D')
	 cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(aa[2]-bb[2])==1)
	 cout<<1;
	else
	 cout<<0;
	return 0;
}
