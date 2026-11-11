#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b==d)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((e==65&&(f==66||f==67))||(e==66&&(f==65||f==67))||(e==67&&(f==66||f==65))||(e==68&&f==69)||(e==69&&f==68))cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(e-f==1||e-f==-1)cout<<1;
	else{
		cout<<0;
    }
	return 0;
}
