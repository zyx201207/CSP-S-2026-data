//GZ-J00235 张哲睿 贵阳市新世界学校 
#include<bits/stdc++.h>
using namespace std;
int a[101][101]={};
bool bb=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int x=(b[0]-'0')*10+(b[1]-'0'),xx=(d[0]-'0')*10+(d[1]-'0');
	int y=b[2]-'A'+1,yy=d[2]-'A'+1;
	if(x==xx){
		cout<<"1";
		if(y>3 && yy>3 || y<=3 && yy<=3){
			cout<<"1";
		}else{
			bb=0;
			cout<<"0";
		}
	}else{
		bb=0;
		cout<<"00";
	}
	if((y+1==yy || y-1==yy) && bb){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
