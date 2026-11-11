#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,cb,cc,cd;
	cin>>ca>>cb>>cc>>cd;
	int za=cb[2]-'A'+1,zb=cd[2]-'A'+1;
	if(ca==cc){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if((cb[0]==cd[0])&&(cb[1]==cd[1])){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((za<=3)&&(zb<=3))||((za>3)&&(zb>3))){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(((za+1==zb)||(za-1==zb))||((za==4)&&(zb==6))){
		cout<<1;
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
