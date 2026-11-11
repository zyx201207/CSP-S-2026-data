#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("tracel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		if(s1[1]==s2[1] && s1[0]==s2[0]){
			b=1;
			if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') or (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')){
				c=1;
				if(abs(s1[2]-s2[2])==1){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
