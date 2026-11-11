#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int pd1=0,pd2=0,pd3=0,pd4=0;
	if(c1==c2){
	pd1=1;
	char p1=s1[2],p2=s2[2];
	int k1=(s1[0]-'0')*10+(s1[1]-'0');
	int k2=(s2[0]-'0')*10+(s2[1]-'0');
	if(k1==k2) {
		pd2=1;
		if((p1<='C'&&p2<='C')||(p1>='D'&&p2>='D')){
			pd3=1;
			if((abs((int)p1-(int)p2)==1&&p1!='D'&&p2!='D')||(p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')){
				pd4=1;
			}
		}
	}
	}
	
	cout<<pd1<<pd2<<pd3<<pd4;
	
}
