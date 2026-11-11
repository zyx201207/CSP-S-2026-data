#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag1=true,flag2=true,flag3=true,flag4=true;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			flag1=false;
			flag2=false;
			flag3=false;
			flag4=false;
		}
	}
	if(flag1==true){
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				flag2=false;
				flag3=false;
				flag4=false;
			}
		}
	}
	if(flag2==true){
		if(s1[2]-s2[2]>=2 || s2[2]-s1[2]>=2){
			if(s1[2]=='A' && s2[2]=='C'){
				flag3=true;
				flag4=true;
			}
			if(s1[2]=='C' && s2[2]=='A'){
				flag3=true;
				flag4=true;
			}
			else{
				flag3=false;
				flag4=false;
			}
		}
		else if(s1[2]=='C' && s2[2]=='D'){
			flag3=false;
			flag4=false;
		}
	}
	if(flag3==true){
		if(s1[2]!=s2[2]-1 && s1[2]!=s2[2]+1 ){
			flag4=false;
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
} 
