#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long l,r,ans,n,yy[N],zuy,yuy;
string a;
char xx[N],cl;
void asd (char xa,char ya){
	if(xa!=ya){
		if(zuy>yuy) ans+=yuy;
		else ans+=zuy;
	}
	if(zuy>yuy){
		zuy=(zuy-yuy);
		yuy=0;
	}else{
		yuy=(yuy-zuy);
		zuy=0;
	}
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>yy[i]>>xx[i];
	}
	l=1;
	r=n;
	zuy=yy[l];
	yuy=yy[r];
	while(l<r){
		if(zuy==0) zuy=yy[l];
		if(yuy==0) yuy=yy[r];
		asd(xx[l],xx[r]);
		if(zuy==0) l++;
		if(yuy==0) r--;
	}
	cout<<ans;
	return 0;
}
