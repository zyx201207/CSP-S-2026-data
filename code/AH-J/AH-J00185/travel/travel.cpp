#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){//两张车票对应的座位不在同一节车厢
		cout<<"0000";
		return 0;
	}
	else{//两张车票对应的座位在同一节车厢
		cout<<"1";
		int zwhr=0,zwhx=0;
		for(int i=0;i<3;i++){
			if(r2[i]>='0'&&r2[i]<='9')zwhr=zwhr*10+(r2[i]-'0');
			if(x2[i]>='0'&&x2[i]<='9')zwhx=zwhx*10+(x2[i]-'0');
		}
		if(zwhr!=zwhx){//两张车票对应的座位不在同一节车厢的同一排
			cout<<"000";
			return 0;
		}
		else{//两张车票对应的座位在同一节车厢的同一排
			cout<<"1";
			if((r2[2]=='F'&&x2[2]=='D')||(x2[2]=='F'&&r2[2]=='D')||(x2[2]!='F'&&r2[2]!='D'&&r2[2]!='F'&&x2[2]!='D')){//两张车票对应的座位在同一节车厢的同一排,且位于过道的同一侧
				cout<<"1";
				if(r2[2]+1==x2[2]||x2[2]+1==r2[2]){//两张车票对应的座位相邻
					cout<<"1";
					return 0;
				}
				else{//两张车票对应的座位不相邻
					cout<<"0";
					return 0;
				}
			}
			else{//两张车票对应的座位在同一节车厢的同一排,且不位于过道的同一侧
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
}
