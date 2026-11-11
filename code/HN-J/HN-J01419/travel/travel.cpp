#include <bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;
bool f = 0;
bool t = 1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	

	
	cin>>c1>>s1>>c2>>s2;
	
	if(s2[2]<'D' && s1[2]<'D' || s2[2]>'D' && s1[2]>'D'){
		f = 1;
	}
	
	if(s1[2]>s1[2]){
		t = 0;
	}
	

	
	
	if(c1 != c2){
		cout<<"0000";
	}else if(s1[1] != s2[1] || s1[0] != s2[0]){
		cout<<"1000";
	}else if(f != 1){
		cout<<"1100";
		
	}else if(t == 1){
			if(s1[2] - '0' != s2[2] - '0'-1){
			cout<<"1110";
		}else{
			cout<<"1111";
		}


	}else if(t == 0){
			if(s1[2] - '0'-1 != s2[2] - '0'){
			cout<<"1110";
		}else{
			cout<<"1111";
		}
	}
	





	return 0;
}
