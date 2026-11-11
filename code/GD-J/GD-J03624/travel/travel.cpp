#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char c[10]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//判断同车间 
	if(c1==c2){
		cout<<1;
		//判断同排 
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int a,b;
			for(int i=0;i<5;i++){
				if(s1[2]==c[i]){
					a=i;
				}
				if(s2[2]==c[i]){
					b=i;
				}
			}
			//判断同侧
			if((a<=2&&b<=2)||(a>=3&&b>=3)){
				cout<<1;
				//判断相邻 
				if((a==b+1)||(b==a+1)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

