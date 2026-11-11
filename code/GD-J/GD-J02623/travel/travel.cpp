#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int s=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			s++;
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')){
				s++;
				if(abs(s1[2]-s2[2])==1)s++;
			}
		}
	}
	for(int i=1;i<=4;i++){
		if(i<=s)cout<<1;
		else cout<<0;
	} 
	return 0;
} 
