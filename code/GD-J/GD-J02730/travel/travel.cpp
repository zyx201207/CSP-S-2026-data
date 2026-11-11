#include <bits/stdc++.h>
using namespace std;

int c1,c2;
int o1=0,o2=0,o3=0,o4=0;
string s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		o1=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			o2=1;
			if(s1[2]<='C' && s2[2]<='C'){
				o3=1;
				if( abs(s1[2]-s2[2]) == 1){
					o4=1;
				}
			}else if(s1[2]>='D' && s2[2]>='D'){
				o3=1;
				o4=1;
			}
		}
	}
	cout<<o1<<o2<<o3<<o4;
	return 0;
}
