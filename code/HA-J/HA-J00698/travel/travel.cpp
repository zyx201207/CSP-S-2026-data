#include<bits/stdc++.h>
using namespace std;
struct train{
	int chexianghao;
	int paihao;
	int liehao;
}t[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++){
		cin>>t[i].chexianghao;
		string zwh;
		cin>>zwh;
		t[i].paihao=(zwh[0]-'0')*10+(zwh[1]-'0');
//		cout<<zwh[2]<<" ";//ts
		if(zwh[2]<='C'){
			t[i].liehao=zwh[2]-'A';
		}
		else{
			t[i].liehao=zwh[2]-'A'+1;
		}
	}
//	cout<<"\nR:"<<t[0].paihao<<","<<t[0].liehao<<" X:"<<t[1].paihao<<","<<t[1].liehao<<"\n";//ts
	if(t[0].chexianghao!=t[1].chexianghao){
		cout<<"0000";
		return 0;
	}
	else if(t[0].paihao!=t[1].paihao){
		cout<<"1000";
		return 0;
	}
	else if(!((t[0].liehao<3 && t[1].liehao<3) || (t[1].liehao>3 && t[0].liehao>3))){
		cout<<"1100";
		return 0;
	}
	else if(max(t[0].liehao,t[1].liehao)-min(t[0].liehao,t[1].liehao)!=1){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
	return 0;
}
