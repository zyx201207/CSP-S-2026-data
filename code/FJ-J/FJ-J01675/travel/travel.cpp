#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool ck[5];
	cin>>c1>>s1>>c2>>s2;
	int zw1=(char)s1[2]-'A'+1,zw2=(char)s2[2]-'A'+1;
	if(c1==c2){
		ck[1]=1;
		if((s1[0]==s2[0]&&(s1[1]==s2[1]))){
			ck[2]=1;
			if(((zw1<=3)&&(zw2<=3))||((zw1>3)&&(zw2>3))){
				ck[3]=1;
				if(abs(zw1-zw2)==1){
					ck[4]=1;
				}else{
					ck[4]=0;
				}
			}else{
				ck[3]=0;
				ck[4]=0;
			}
		}else{
			ck[2]=0;
			ck[3]=0;
			ck[4]=0;
		}
	}else{
		ck[1]=0;
		ck[2]=0;
		ck[3]=0;
		ck[4]=0;
	}
	cout<<ck[1]<<ck[2]<<ck[3]<<ck[4];
	return 0;
}
