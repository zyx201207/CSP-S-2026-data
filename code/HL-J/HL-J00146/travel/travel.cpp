#include<bits/stdc++.h>
using namespace std;
string c1;
string s1[3];
string c2;
string s2[3]; 
int a[5];
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    for(int i = 1;i<=17;i++){
    	for(int j =1;j<=18;j++){
    		cin>>c1>>si[i]>>c2>>s3[i];
		}
	}
    for(int i = 1;i<=17;i++){
    	if(i!=1&&i!=16&&c1==c2){
    		a[0] = 1;
		}else{
			a[0] = 0;
		}
	}
		for(int i = 1;i<=17;i++){
		for(int j = 1;j<=18;j++){
				if(i!=1&&i!=16&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
					a[1] = 1;
				}else{
					a[1] = 0;
				}			
		}
	}
		for(int i = 1;i<=17;i++){
			for(int j = 1;j<=18;j++){
				if(i!=1&&i!=16&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]-'0'<3&&s2[3]-'0'<=3||s1[3]-"0"==4&&s2[3]-"0"==5||s1[3]-"0"==5&&s2[3]-"0"==4){
					a[2] = 1;
				}else{
					a[2] = 0;
				}
			}
		}
		for(int i = 1;i<=17;i++){
			for(int j = 1;j<=18;j++){
					if(i!=1&&i!=16&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]-'0'<3&&s2[3]-'0'<=3||s1[3]-"0"==4&&s2[3]-"0"==5||s1[3]-"0"==5&&s2[3]-"0"==4&&s1[2]-'0'==s2[2]-'0'+1||s1[2]-'0'==s2[2]-'0'-1){
						a[3] = 1;
					}else{
						a[3] = 0;
					}
			}
		}
		cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}

