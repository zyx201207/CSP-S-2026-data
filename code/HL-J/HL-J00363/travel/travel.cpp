#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen(travel,std.in)
	string c1,s1,c2,s2;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		if((s1[0]*10+s1[1])==(s2[0]*10+s2[1])){
			b=1;
			if((((s1[2]>=65)&&(s1[2]<=67))&&((s2[2]>=65)&&(s2[2]<=67)))||(((s1[2]==68)||(s1[2]==70))&&((s2[2]==68)||(s2[2]==70)))){
				c=1;
				if(abs(s1[2]-s2[2])==1)
					d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
