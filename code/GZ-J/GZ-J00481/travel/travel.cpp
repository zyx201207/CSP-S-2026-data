//GZ-J00481 遵义市第十九中学 刁奕杰 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool st=true;
	int a1[4],a2[4];
	char b1,b2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<true;
	}else{
		cout<<false;
		st=false;
	}
	if(st==true){
		for(int i=0;i<2;i++){
			if(s2[i]!=s1[i]) st=false;
		}
		cout<<st;
	}else{
		cout<<false;
	}
	if(st==true){
		b1=s1[3],b2=s2[3];
		if(b1>='D'&&b2>='D'){
			cout<<true;
		}else if(b1<'D'&&b2<'D'){
			cout<<true;
		}else{
			cout<<false;
			st=false;
		}
	}else{
		cout<<false;
	}
	if(st==true){
		if(b1+2==b1||b2+2==b1+1){
			cout<<true;
		}else{
			cout<<false;
		}
	}else{
		cout<<false;
	}
	return 0;
}

