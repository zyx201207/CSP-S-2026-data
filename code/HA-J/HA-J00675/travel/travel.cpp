#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int c1,c2;//小R车票上的车厢号 小x车票上的车厢号 
	string s1,s2;//小R车票上的座位号 小x车票上的座位号 
	
	cin>>c1>>s1>>c2>>s2;//输入
	
	//判断是否在同一车厢
	if(c1 == c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	//判断是否在同一车厢的同一排
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	//判断是否在同一车厢的同一排同一侧
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A') || ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	char a = s1[2];
	char b = s2[2];
	//判断是否在同一车厢的同一排同一侧相邻 
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A') 
	|| ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))) && (char(a-1) == b || char(a+1) == b)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
