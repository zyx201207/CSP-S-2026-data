//GZ-J00506 黄宇瀚 贵阳市观山湖区普瑞学校
#include<bits/stdc++.h>
using namespace std;
int main(){
	string a[5];
	int vis[5]={0,0,0,0};
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	string q=a[2];
	string w=a[4];
	char z=q[0]+q[1];
	char x=w[0]+w[1];
	char e=q[2];
	char r=w[2];
	if(a[1]==a[3]){
		vis[0]=1;
		if(z==x){
			vis[1]=1;
			if(e-r==1&&e!='D'&&r!='C'||e-r==-1&&e!='C'&&r!='D'||e-r==2&&e!='F'&&r!='C'||e-r==-2&&e!='C'&&r!='F'){
				vis[2]=1;
				if(e-r==1&&e!='D'&&r!='C'||e-r==-1&&e!='C'&&r!='D')
				vis[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++) cout<<vis[i];
	return 0;
}
