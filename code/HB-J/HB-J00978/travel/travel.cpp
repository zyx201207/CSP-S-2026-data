#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    int a1=0,a2=0,a3=0,a4=0;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
		a1=1;
		if(s2[0]==s3[0] and s2[1]==s4[1]){
			a2=1;
			if(((s2[2]=='F' or s2[2]=='D') and (s4[2]=='F' or s4[2]=='D'))or((s2[2]!='F' and s2[2]!='D') and (s4[2]!='F' and  s4[2]!='D'))){
				a3=1;
				if((s2[2]=='F' and s4[2]=='D') or (s2[2]=='D' and s4[2]=='F')){
					a4=1;
				}
				if((s2[2]=='A' and s4[2]=='B') or (s2[2]=='B' and s4[2]=='C')){
					a4=1;
				}
				if((s2[2]=='B' and s4[2]=='A') or (s2[2]=='C' and s4[2]=='B')){
					a4=1;
				}
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
