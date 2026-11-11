#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";x=true;
	}else cout<<"0";
	//chexiang
	if(b[0]==d[0]&&b[1]==d[1]&&x){
		cout<<"1";y=true;
	}else cout<<"0";
	//pai
	if(x&&y&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]<='D'&&d[2]>='F'))){
		cout<<"1";
	}else cout<<"0";
	//ce
	int m=abs((int)b[2]-d[2]);
	if(m==1&&(b[2]!='C'&&d[2]!='D')&&(b[2]!='D'&&d[2]!='C')&&x&&y) cout<<"1";
	else cout<<"0";
	return 0;
}
