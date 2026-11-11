#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	bool f=1;
	if(r1==x1)cout<<1;
	else {
		f=0;
		cout<<0;
	}
	for(int i=0;i<2;i++)
	{
		if(r2[i]!=x2[i]){
			f=0;
			break;
		}
	}
	if(f)cout<<1;
	else cout<<0;
	if(!f)cout<<0;
	else if(r2[2]<='C'&&x2[2]<='C'||r2[2]>='D'&&x2[2]>='D')cout<<1;
	else {
		f=0;
		cout<<0;
	}
	if(!f)cout<<0;
	else {
		if(r2[2]=='D'||x2[2]=='D')cout<<1;
		else if(r2[2]=='B'||x2[2]=='B')cout<<1;
		else cout<<0;
	}
	return 0;
}
