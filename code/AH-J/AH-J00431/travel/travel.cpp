#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
int a1,a2,b1,b2;
char m1,m2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=(c1[0]-'0')*10+c1[1]-'0';//chexiang
	a2=(c2[0]-'0')*10+c2[1]-'0';
	b1=(s1[0]-'0')*10+s1[1]-'0';//zuowei
	b2=(s2[0]-'0')*10+s2[1]-'0';
	m1=s1[2],m2=s2[2];
	if(a1==a2){//1
		if(b1==b2){//1
			if(m1<='C'&&m2<='C'){//1
				if(abs(m1-m2)==1)cout<<"1111";
				else cout<<"1110";
			}else if(m1>='D'&&m1>='D')cout<<"1111";
			else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
