//GZ-00086 李凤涛 六盘水市第十二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char x1[2]={c1[0],c1[1]};
	char x2[2]={c2[0],c2[1]};
	char z1[5]={s1[0],s1[1],s1[2]};
	char z2[5]={s2[0],s2[1],s2[2]};
	if(x1[1]=='1'||x2[1]=='1'&&(x1[0]=='0'||x2[0]=='0')){
		cout<<"0000";
		return 0;
	}
	else if(x1[1]=='6'){
		cout<<"0000";
		return 0;
	}
	if(x1[0]==x2[0]&&x1[1]==x2[1]){
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(x1[0]!=x2[0]||x1[1]!=x2[1]) {
		cout<<"0000";
		return 0;
	}
	if(z1[0]==z2[0]){
		if(z1[1]==z2[1]){
			cout<<"1";
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"000";
		return 0;
	}
	if(z1[2]<='C'){
		if(z2[2]<='C')cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	else {
		if(z2[2]<='C'){
			cout<<"00";
			return 0;
		}
		else cout<<"1";
	}
	if(z1[2]-z2[2]==1||z2[2]-z1[2]==1){
		cout<<"1";
	}
	else cout<<"0";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
