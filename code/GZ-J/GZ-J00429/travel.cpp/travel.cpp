//GZ-J00429 贵州省铜仁市印江县木黄中学  银朗 
#include <iostream>
using namespace std;
int main(){
	int c1,s1,c2,s2;
	string>>c1>>s1>>c2>>s2;
	cin>>c1>>s1>>c2>>s2;
	int s[10];
	for(int i=1;i<=10;i++){
		if(c1==c2){
			s[1]=1;
		}
		else{
			s[1]=0;
		}
		if(s1[1]+s1[2]==s2[1]+s2[2]){
			s[2]=1;
		}
		else{
			s[2]=0;
		}
		if(s1[1]+s1[2]==s2[1]+s2[2]&&s1[3]<=c&&s2[3]<=c||s1[3]>c&&s2[3]>c){
			s[3]=1;
		}
		else{
			s[3]=0;
		}
		if(c1==c2&&s1[1]+s1[2]==s2[1]+s2[2]&&s1[1]+s1[2]==s2[1]+s2[2]&&s1[3]<=c&&s2[3]<=c||s1[3]>c&&s2[3]>c&&s1[1]+s1[2]+1==s2[1]+s2[2]||s1[1]+s1[2]-1==s2[1]+s2[2]){
			s[4]=1;
		}
		else{
			s[4]=0;
		}
		cout<<s;
	}
	retern 0;
};

