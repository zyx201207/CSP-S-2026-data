#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,zw1,zw2;
bool zw32=false,zw31=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2){
		cout<<1;
		char zw11=zw1[0];
		char zw12=zw1[1];
		char zw21=zw2[0];
		char zw22=zw2[1];
		if(zw11==zw21&&zw12==zw22){
			cout<<1;
			char zw13=zw1[2];
			char zw23=zw2[2];
			if(zw13=='D'||zw13=='E') zw31=true;
			if(zw23=='D'||zw23=='E') zw32=true;
			if(zw31==zw32){
				cout<<1;
				if(zw31) cout<<1;
				else if(abs(zw13-zw32)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
