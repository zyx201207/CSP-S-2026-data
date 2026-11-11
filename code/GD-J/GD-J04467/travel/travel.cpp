#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}else{
		cout << 1;
	}
	node r;
	node r2;
	if(s1[0]=='0'){
		r.x = (s1[1]-'0');
	}else{
		r.x = 10+(s1[1]-'0');
	}
	if(s2[0]=='0'){
		r2.x = (s2[1]-'0');
	}else{
		r2.x = 10+(s2[1]-'0');
	}
	r.y = (s1[2]-'A'+1);
	r2.y = (s2[2]-'A'+1);
	bool near_r = 0;
	bool near_r2 = 0;
	if(r.y>=4){
		near_r = 1;
	}
	if(r2.y>=4){
		near_r2 = 1;
	}
	if(r.x==r2.x){
		cout << 1;
		if(near_r==near_r2){
			cout << 1;
			if(abs(r.y-r2.y)==1&&r.x==r2.x||abs(r.x-r2.x)==1&&r.y==r2.y){
				cout << 1;
			}else{
				cout << 0;
			}
		}else{
			cout << "00";
		}
	}else{
		if(abs(abs(r.y-r2.y)==1&&r.x==r2.x||abs(r.x-r2.x)==1&&r.y==r2.y)){
			cout << "001";
		}else{
			cout << "000";
		}
	}
	return 0;
} 
