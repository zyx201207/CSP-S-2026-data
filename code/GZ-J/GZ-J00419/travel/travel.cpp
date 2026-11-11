//GZ-J00419个人报名毛诗淳 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",std);
	freopen("travel.out","w",std);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";
			return 0;
		}		
	}
	cout<<'1';
	if(b[0]==d[0]&&d[1]==b[1]){	
		cout<<'1';
		}
	else{
		cout<<"000";
		return 0;
	}
	if((d[2]-'A'<3&&b[2]-'A'<3)||(d[2]-'A'>3&&b[2]-'A'>3)){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if(d[2]-b[2]==1||b[2]-d[2]==1){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	
	
	return 0;
}
