//GZ-J00032 贵阳市第十九中学 徐福余
#include<iostream>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	string a1,a2,b1,b2;
	cin>>a1;
	cin>>a2;
	cin>>b1;
	cin>>b2;
	if(a1==b1){
		cout<<1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<1;
			cout<<1;
			cout<<1;	
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	} 
		
	return 0;
}



