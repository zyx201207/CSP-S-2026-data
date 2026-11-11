#include<bits/stdc++.h>
using namespace std;

string xiang1,zuo1,xiang2,zuo2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>xiang1>>zuo1>>xiang2>>zuo2;
	int x1=(xiang1[0]-'0')*10+(xiang1[1]-'0');
	int x2=(xiang2[0]-'0')*10+(xiang2[1]-'0');
	if(zuo1[2]=='F') zuo1[2]--;
	if(zuo2[2]=='F') zuo2[2]--;
	if(x1==x2) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	int z1=(zuo1[0]-'0')*10+(zuo1[1]-'0');
	int z2=(zuo2[0]-'0')*10+(zuo2[1]-'0');
	if(z1==z2) cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	int hao1=zuo1[2]-'A'+1;
	int hao2=zuo2[2]-'A'+1;
	if((hao1<=3&&hao2<=3)||(hao1>=4&&hao2>=4)) cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if(max(hao1,hao2)-min(hao1,hao2)==1) cout<<'1';
	else cout<<'0';
	return 0;
}
