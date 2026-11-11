//GZ-J00345 遵义市第四中学 李禹宸 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000");
		return 0;
	}else{
		printf("1");
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	int n=0;
	if(s1[2]<='C'){
		n++;
	}
	if(s2[2]<='C'){
		n++;
	}
	if(n==2||n==0){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
