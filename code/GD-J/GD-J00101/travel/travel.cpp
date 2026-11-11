#include<bits/stdc++.h>
using namespace std;
string c1,c2;int num1,num2;char l1,l2,pos[10]="ABC DF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>num1>>l1>>c2>>num2>>l2;
	if(c1==c2){
		cout<<1;
		if(num1==num2){
			cout<<1;
			int p1=0,p2=0;
			for(int i=0;i<6;i++){
				if(pos[i]==l1)p1=i;
				if(pos[i]==l2)p2=i;
			}
			if((p1<3&&p2<3)||(p1>3&&p2>3)){
				cout<<1;
				if(abs(p1-p2)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
