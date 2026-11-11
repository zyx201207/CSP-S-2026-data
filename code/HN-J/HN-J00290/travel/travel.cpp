#include<bits/stdc++.h>
using namespace std;
struct train{
	int chexiang;
	int zhuiwei;
	char zimu;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	train a[2]={};
	for(int i=0;i<2;i++){
		cin>>a[i].chexiang>>a[i].zhuiwei>>a[i].zimu;
	}
	if(a[0].chexiang==a[1].chexiang){
		cout<<"1";
		if(a[0].zhuiwei==a[1].zhuiwei){
			cout<<"1";
			if((a[0].zimu<'69'&&a[1].zimu<'69')||(a[0].zimu>='69'&&a[1].zimu>='69')){
				cout<<"1";
				if(('a[0].zimu'+1=='a[1].zimu')||('a[0].zimu'-1=='a[1].zimu')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else {
				for(int i=0;i<2;i++){
					cout<<"0";
				}
			}
		}else{
			for(int i=0;i<3;i++){
				cout<<"0";
			}
		}
	}else{
		for(int i=0;i<4;i++){
			cout<<"0";
		}
	}
	return 0;
}
