#include<bits/stdc++.h>
using namespace std;
int rc,xc,rs,xs,ans[10];
char rz,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>rc>>rs>>rz>>xc>>xs>>xz;
	if(rc==xc)ans[0]=1;
	if(rc==xc and rs==xs)ans[1]=1;
	if(rc==xc and rs==xs and int(rz)<='C' and int(rz)>='A' and int(xz)<='C' and int(xz)>='A')ans[2]=1;
	if(rc==xc and rs==xs and int(rz)<='F' and int(rz)>='D' and int(xz)<='F' and int(xz)>='D')ans[2]=1;
	if(rc==xc and rs==xs and int(rz)<='C' and int(rz)>='A' and int(xz)<='C' and int(xz)>='A' and abs(int(rz)-int(xz)==1))ans[3]=1;
	if(rc==xc and rs==xs and int(rz)<='F' and int(rz)>='D' and int(xz)<='F' and int(xz)>='D' and abs(int(rz)-int(xz)==1))ans[3]=1;
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}

