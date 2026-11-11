#include<bits/stdc++.h>
using namespace std;
string ca,cb,za,zb;
int pa,pb,xa,xb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>za>>cb>>zb;
	if(ca!=cb){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	for(int i=0;i<=1;i++) pa=pa*10+(za[i]-'0');
	for(int i=0;i<=1;i++) pb=pb*10+(zb[i]-'0');
	if(pa!=pb){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	xa=za[2]-'A'+1;xb=zb[2]-'A'+1;
	if((xa<=3&&xb<=3)||(xa>=4&&xb>=4)) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(xa-xb)==1) cout<<"1";
	else cout<<"0";
	return 0;
}
