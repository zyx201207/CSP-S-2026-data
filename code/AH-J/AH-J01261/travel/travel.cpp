#include <bits/stdc++.h>
using namespace std;
int a,b;
char ch[10];
signed main(){
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>ch[1]>>ch[2]>>ch[3]>>b>>ch[4]>>ch[5]>>ch[6];
	int a1=(ch[1]-'0')*10+(ch[2]-'0');
	int b1=(ch[4]-'0')*10+(ch[5]-'0');
	int za=ch[3]-'A'+1;
	int zb=ch[6]-'A'+1;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a1==b1){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((za<=3&&zb<=3)||(za>3&&zb>3)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	int f=0;
	if(abs(za-zb)==1&&(za!=3&&zb!=4)&&(za!=4&&zb!=3)){
		f=1;
	}
	if((za==4&&zb==6)||(zb==4&&za==6)){
		f=1;
	}
	cout<<f;
	return 0;
}

