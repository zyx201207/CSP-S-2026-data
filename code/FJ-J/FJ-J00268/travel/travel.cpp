#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool flag1=true,flag2=true,flag3=true,flag4=true;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a1>>a2>>b1>>b2;
	for(int i=0;i<2;++i){
		if(a1[i]!=b1[i]) flag1=false;
	}
	for(int i=0;i<2;++i){
		if(a2[i]!=b2[i]||flag1==false) flag2=false;
	}
	for(int i=2;i<=2;++i){
		if((a2[i]>'C'&&b2[i]<='C')||(a2[i]<='C'&&b2[i]>'C')||flag2==false) flag3=false;
		if(abs(int(a2[i]-b2[i]))!=1||flag3==false) flag4=false;
	}
	cout<<flag1<<flag2<<flag3<<flag4<<endl;
	return 0;
}
