#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	//chexiang
	if(r1==x1)cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	//pai
	if(r2[0]==x2[0]&&r2[1]==x2[1])cout<<1;
	else{
		cout<<"000"<<endl;
		return 0;
	}
	//ce
	if((r2[2]<='C'&&x2[2]<='C')||(r2[2]>='D'&&x2[2]>='D'))cout<<1;
	else{
		cout<<"00"<<endl;
		return 0;
	}
	//xianglin
	int a=r2[2],b=x2[2];
	if(abs(a-b)==1&&max(a,b)!='D')cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}
