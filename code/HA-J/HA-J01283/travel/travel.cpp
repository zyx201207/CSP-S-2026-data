#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0000";
	}else{
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A')){
				if(max(s1[2],s2[2])-min(s1[2],s2[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if((s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D')){
				cout<<"1111";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}
	return 0;
}

