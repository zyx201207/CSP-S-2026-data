#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;//R车厢号、座位号，X的车厢号、座位号
	cin>>c1>>s1>>c2>>s2;
	//判断是否在同一个车厢
	if(c1==c2){
		cout<<1;
		//判断在不在同一排 
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			//判断是否在过道同一侧
			//在左侧就不用判断是不是相邻 
			//在右侧时，如果其中一个是B就相邻
			//佛则不相邻 
			if(s1[2]-'A'>2&&s2[2]-'A'>2){
				cout<<"11";
			}
			else if(s1[2]-'A'<3&&s2[2]-'A'<3){
				cout<<1;
				if(s1[2]=='B'||s2[2]=='B')cout<<1;
				else cout<<"0"; 
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

