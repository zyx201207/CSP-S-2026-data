#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long r,x,q,w;
	string r1,x1;
	cin>>r>>r1>>x>>x1;
	if(r!=x)
		cout<<"0000";
	else
		cout<<"1";
		if(r%2==0)
			cout<<"0";
		else
			cout<<"1";
		if(q%2==0)
			cout<<"0";
		else
			cout<<"1";
		if(w%2==0)
			cout<<"0";
		else
			cout<<"1";


	return 0;
}
