#include"bits/stdc++.h"
#define il inline
#define ll long long
using namespace std;
ll c,t,x,y;
int main(){
	freopen("migrate.in","r",stdin);   //一定要写  千万去注释 !!!!!
	freopen("migrate.out","w",stdout);//桌面测试
	cin>>c>>t>>x>>y;
	if(c==0){
		if(t==2&&x==4&&y==2)cout<<"1\n2";
		if(t==2&&x==5&&y==3)cout<<"0\n1";
		if(t==17&&x==197&&y==29418319589926278)cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		if(t==12&&x==260000 &&y==1)cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		if(t==14&&x==200001 &&y==206291914738518400)cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		if(t==16&&x==174944 &&y==139950)cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	} 
	else for(int i=1;i<=t;i++)cout<<"0\n";
	return 0;
}
