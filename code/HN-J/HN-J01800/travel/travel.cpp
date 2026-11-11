#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin >>c1>>s1>>c2>>s2;
	bool flag[5]={};
	if(c1==c2){
		flag[1]=true;
		int hang1=(s1[0]-'0')*10+(s1[1]-'0');
		int hang2=(s2[0]-'0')*10+(s2[1]-'0');
		if(hang1==hang2){
			flag[2]=true;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				flag[3]=true;
				if(abs(int(s1[2])-int(s2[2]))==1){
					if(!((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D'))){
						flag[4]=true;
					}
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout <<flag[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
