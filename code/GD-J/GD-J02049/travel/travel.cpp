#include<bits/stdc++.h>
using namespace std;
struct{
	int cx;
	string wz;
}X,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>X.cx>>X.wz>>r.cx>>r.wz;
	if(X.cx==r.cx) cout<<"1";
	else cout<<"0";
	if(X.wz[0]+X.wz[1]==r.wz[0]+r.wz[1]) cout<<"1";
	else cout<<"0";
	if(X.wz[2]+1==r.wz[2]||X.wz[2]+2==r.wz[2]||X.wz[2]-1==r.wz[2]||X.wz[2]-2==r.wz[2]) cout<<"1";
	else if(X.wz[2]=='D' and r.wz[2]=='F') cout<<"1";
	else cout<<"0";
	if(X.wz[2]+1==r.wz[2]||X.wz[2]+2==r.wz[2]||X.wz[2]-1==r.wz[2]||X.wz[2]-2==r.wz[2]){
		if(X.wz[2]+1==r.wz[2]||X.wz[2]-1==r.wz[2]) cout<<"1";
	}
	else if(X.wz[2]=='D'&&r.wz[2]=='F') cout<<"1";
	else cout<<"0";
	return 0;
} 
