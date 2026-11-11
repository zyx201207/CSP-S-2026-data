#include<bits/stdc++.h>
using namespace std;
string a1,a2;
string b1,b2;
bool flag1=1,flag2=1;
int flag3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	for(int i=0;i<=1;i++){//chexiang
		if(a1[i]!=b1[i]){
//			cout<<"che ";
			cout<<0;
			flag1=0;
		}
	}
	if(flag1){
//		cout<<"che ";
		cout<<1;
	}
	if(flag1){//pai
		for(int i=0;i<2;i++){
			if(a2[i]!=b2[i]){
//				cout<<"pai ";
				cout<<0;
				flag2=0;
				break;
			}
		}
		if(flag2){
//			cout<<"pai ";
			cout<<1;//tong
		}
	}else{
//		cout<<"pai ";
		flag2=0;
		cout<<0;
	}
	if(flag2){//ce
		if('C'>=a2[2] && a2[2]>='A' && 'C'>=b2[2] && b2[2]>='A'){//tong
			flag3=1;
//			cout<<"ce ";
			cout<<1;
		}else if('F'>=a2[2] && a2[2]>='D' && 'F'>=b2[2] && b2[2]>='D'){//tong
			flag3=2;
//			cout<<"ce ";
			cout<<1;
		}else{
//			cout<<"ce ";
			cout<<0;
		}
	}else{
//		cout<<"ce ";
		cout<<0;
	}
	if(flag3!=0){//xiangling
		if(flag3==1){
			if(a2[2]==b2[2]+1||a2[2]==b2[2]-1){
//				cout<<"xl ";
				cout<<1;
			}else{
//				cout<<"xl ";
				cout<<0;
			}
		}else if(flag3==2){
			if(a2[2]=='D'&&b2[2]=='F' || a2[2]=='F'&&b2[2]=='D'){
//				cout<<"xl ";
				cout<<1;
			}else{
//				cout<<"xl ";
				cout<<0;
			}
		}
			
	}else{
//		cout<<"xl ";
		cout<<0;
	}
	return 0;
}
