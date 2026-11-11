//黄烨 GZ-J00059 毕节七星关东辰实验学校 
#include<iostream>
#include<string> 
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int flag=0;
	int flag1=0;
	int flag2=0;
	for(int i=0;i<=(int)c1.size();i++){
		if(c1[i]!=c2[i]){
			flag=1;
		}
	}
	for(int i=0;i<=(int)s1.size()-2;i++){
		if(s1[i]!=s2[i] || flag==1){
			flag1=1;
		}
	}
	for(int i=(int)s1.size();i>=(int)s1.size()-1;i--){
		flag2=1;
		if(('A'<=s1[i] && s1[i]<='C' && 'A'<=s2[i] && s2[i]<='C') || ('D'<=s1[i] && s1[i]<='F' && 'D'<=s2[i] && s2[i]<='F')){
			flag2=0;
		}
		if(flag1==1){
			flag2=1;
		}
	}
	int flag3=0;
	for(int i=(int)s1.size();i>=(int)s1.size()-1;i--){
		flag3=1;
		if(flag2==0){
			if(s2[i]-s1[i]==1){
				flag3=0;
			}
		}
	}
	if(flag==1){
		printf("0");
	}else{
		printf("1");
	}
	if(flag1==1){
		printf("0");
	}else{
		printf("1");
	}
	if(flag2==1){
		printf("0");
	}else{
		printf("1");
	}
	if(flag3==1){
		printf("0");
	}else{
		printf("1");
	}
	return 0;
}
