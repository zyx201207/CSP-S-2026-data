#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	//两张车票对应的座位是否在同一节车厢;
	bool f=1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	//两张车票对应的座位是否在同一节车厢的同一排;
	for(int i=0;i<c1.size()-1;i++){
		if(c1[i]!=c2[i]){
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧;
	if(c1[2]=='C'&&c2[2]=='D'){
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if(c1[2]+1==c2[2]||c1[2]-1==c2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
