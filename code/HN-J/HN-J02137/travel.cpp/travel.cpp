#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char A='1',B='2',C='3',D='5',F='6';
	int a,b;
    string s1,s2;
    cin >> a>> s1 >> b >> s2;
    if(a-b==0 and s2-s1==1){
    	cout << "1111";
	}
    if((a-b==0 and s2-s1!=1) or (b-a==0 and s1-s2!=1)){
    	cout << "1110";
	}
	if((a-b==0 and s2-s1==2) or (b-a==0 and s1-s2==2)){
		cout << "1100";
	}
	if((a-b==0 and s2-s1>2) or (b-a==0 and s1-s2>2)){
		cout << "1000";
	}
	if(a-b!=0 or b-a!=0){
		cout << "0000";
	}
	
	
	
	
	
	rsturn 0;
}
