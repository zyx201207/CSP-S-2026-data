#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char x1,x2;
	cin>>c1>>s1>>x1>>c2>>s2>>x2;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((x1<='C'&&x2<='C')||(x1>='D'&&x2>='D'))cout<<1;
			else cout<<0;
		}else cout<<"00";
		if((abs(x1-x2)+abs(s1-s2)==1)&&(!(x1=='C'&&x2=='D')))cout<<1;
		else cout<<0;
	}else puts("0000");
	return 0;
}
