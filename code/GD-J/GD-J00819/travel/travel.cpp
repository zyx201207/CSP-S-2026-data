#include<bits/stdc++.h>
using namespace std;
int x,y;
bool check(string a,string b){
	if(x-65<=2){
		if(y-65<=2){
			return 1;
		}
		return 0;
	}else{
		if(y-65>2){
			return 1;
		}
		return 0;
	}
}
bool check2(string a,string b){
	if(x-65<=2&&y-65<=2){
		if(y-1==x||y+1==x){
			return 1;
		}
		return 0;
	}else if(x-65>2&&y-65>2){
			return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			x=s1[2];
			y=s2[2];
			if(check(s1,s2)){
				cout<<1;
				if(check2(s1,s2)){
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

