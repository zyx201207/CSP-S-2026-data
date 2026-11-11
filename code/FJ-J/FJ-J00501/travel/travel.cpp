#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool flag=false,flag1=false,flag2=false,flag3=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<s1<<c2<<s2;
	//两张车票对应的座位是否在同一节车厢
	if(c1==c2){
		cout<<'1';
		//两张车票对应的座位是否在同一节车厢的同一排
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<'1';
			//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
			if(!((s1[s1.size()]=='C'&&s2[s2.size()]=='D')||(s1[s1.size()]=='D'&&s2[s2.size()]=='C'))&&(s1[s1.size()]-s2[s2.size()]<=2)){
				cout<<'1';
				// 两张车票对应的座位是否相邻
				if(s1[s1.size()]-1==s2[s2.size()]||s1[s1.size()]+1==s2[s2.size()])
					cout<<'1';
				else
					cout<<'0';
			}
			else{
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
