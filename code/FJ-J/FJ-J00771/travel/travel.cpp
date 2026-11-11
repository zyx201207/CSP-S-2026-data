#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
char c[]={'A','B','C','D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1=1;
		
	}else{
		ans1=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&ans1==1){
		ans2=1;
	}else{
		ans2=0;
	}
	int k1,k2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		k1=1;
	}else{
		k1=2;
	}if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		k2=1;
	}else{
		k2=2;
	}
	if(k1==k2&&ans1==1&&ans2==1){
		ans3=1;
	}else{
		ans3=0;
	}
	for(int i=0;i<5;i++){
		if(s1[2]==c[i])k1=i;
		if(s2[2]==c[i])k2=i;
	}
	if(abs(k1-k2)==1&&ans1==1&&ans2==1&&ans3==1){
		ans4=1;
	}if(k1==2&&k2==3){
		ans4=0;
	}if(k1==3&&k2==2){
		ans4=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
