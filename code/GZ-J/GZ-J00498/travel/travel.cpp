//GZ-J00498 贵阳市第十八中学 李翼辰 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	bool x,y;
	if(s1[2]>='A'&&s1[2]<='C'){
		x=0;
	}else{
		x=1;
	}
	if(s2[2]>='A'&&s2[2]<='C'){
		y=0;
	}else{
		y=1;
	}
	if(x==y){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
