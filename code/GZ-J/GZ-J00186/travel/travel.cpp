//GZ-J00186 六盘水市第三中学 柴大寓 
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[4]={0,0,0,0};
bool d(char a,char b){
	bool r=false,t=false;
	char a1[3]={'A','B','C'};
	char b1[2]={'D','F'};
	for(int i=0;i<3;i++){
		if(a==a1[i]) r=true;
		if(b==a1[i]) t=true;
	if(r&&t) return (r&&t);
	else{
		r=false;t=false;
	}
	}for(int i=0;i<2;i++){
		if(a==b1[i]) r=true;
		if(b==b1[i]) t=true;
	}
	return (r&&t);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!="01"&&c1!="16"){
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) a[1]=1;
		if(d(s1[2],s2[2])){
		a[2]=1;	
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) a[3]=1;
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
return 0;
} 
