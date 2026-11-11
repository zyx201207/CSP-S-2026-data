#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,x1,x2,y1,y2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
		x1=s1[0];
		x2=s1[1];
		z1=s1[2];
		y1=s2[0];
		y2=s2[1];
		z2=s2[2];
	
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(x1==y1&&x2==y2){
		cout<<1;
		if(z1<="C"&&z1>="A"&&z2<="C"&&z2>="A"){
			cout<<1;
			if(z1=="A"&&z2=="B"){
				cout<<1;
			}else if(z1=="B"&&z2=="A"){
				cout<<1;
			}else if(z1=="B"&&z2=="C"){
				cout<<1;
			}else if(z1=="C"&&z2=="B"){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(z1<="F"&&z1>="D"&&z2<="F"&&z2>="D"){
			cout<<1;
			cout<<1;
			return 0;
		}else{
			cout<<0;
			cout<<0;
			return 0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
}
