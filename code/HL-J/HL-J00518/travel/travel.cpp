#include <bits/stdc++.h>
using namespace std;
int main(){
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a1,b1,a2,b2,a3,b3;//a1 -> a de chexiang, b1 b de chexiang, a2 -> a de hangshu, b2 -> b de hangshu, a3 -> a de shuzizuoweihao, b3 -> b de shuzizuoweihao
	string stra3,strb3;//a3 -> a de zuoweihao, b -> b de zuoweihao
	
	cin>>a1>>a2>>stra3>>b1>>b2>>strb3;
	
	if(stra3=="A"){
		a3=1;
	}else if(stra3=="B"){
		a3=2;
	}else if(stra3=="C"){
		a3=3;
	}else if(stra3=="D"){
		a3=4;
	}else if(stra3=="E"){
		a3=5;
	}else if(stra3=="F"){
		a3=6;
	}
	
	if(strb3=="A"){
		b3=1;
	}else if(strb3=="B"){
		b3=2;
	}else if(strb3=="C"){
		b3=3;
	}else if(strb3=="D"){
		b3=4;
	}else if(strb3=="E"){
		b3=5;
	}else if(strb3=="F"){
		b3=6;
	}
	
	
	if(a1==b1){
		cout<<1;
		if(a2==b2){
			cout<<1;
			if((a3<=3 && b3<=3) || (a3>=4 && b3>=4)){
				cout<<1;
				if(abs(a3-b3)==1 && !((a3==3 && b3==4) || (a3==4 && b3==3))){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	
	return 0;
}
