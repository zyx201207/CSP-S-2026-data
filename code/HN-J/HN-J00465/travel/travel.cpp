#include <bits/stdc++.h>
using namespace std;
int tf[4];
string a1,a2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1[0]==a2[0]&&a1[1]==a2[1]){
		tf[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			tf[1]=1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				tf[2]=1;
				if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
					tf[3]=1;
				}
			}else if((s1[2]=='D'||s2[2]=='D')&&(s1[2]=='F'||s2[2]=='F')){
				tf[2]=1;
				if(s1[2]-s2[2]==-2||s1[2]-s2[2]==2){
					tf[3]=1;
				}
			}
		}
	}
	cout<<tf[0]<<tf[1]<<tf[2]<<tf[3];
	return 0;
}
