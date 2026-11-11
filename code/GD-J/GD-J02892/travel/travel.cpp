#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//两是否在同一节车厢
	if(c1 == c2) cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	//是否在同一节车厢的同一排 
	if(s1[0] != s2[0] or s1[1] != s2[1]) {
		cout<<0<<0<<0;
		return 0;
	}
	else cout<<1;
	//两是否在同一节车厢的同一排且位于过道的同一侧
	if(s1[2]>='A' and s1[2]<='C'){
		if(s2[2]>='A' and s2[2]<='C'){
			cout<<1;
			//ABC两张车票对应的座位是否相邻 
			if(s1[2] - s2[2] == 1 or s1[2] - s2[2] == -1){
				cout<<1;
			}
			else cout<<0;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	else{//只有俩坐位必相邻 
		if(s2[2] == 'D' or s2[2] == 'F'){
			cout<<1<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	return 0;
} 
