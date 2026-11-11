#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s;
long long t1,t3;
char t2,t4;
int t;
void fl(){
	s=s2;
	t=s.size();
	for(int i=0;i<t-1;i++){
		t1=t1*10+int(s[i]-'0');
	}
	t2=s[2];
	s=s4;
	t=s.size();
	for(int i=0;i<t-1;i++){
		t3=t3*10+int(s[i]-'0');
	}
	t4=s[2];
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s1>>s2>>s3>>s4;
	fl(); 
	if(s1==s3){
		if(t1==t3){
			if(t2<='C' && t4<='C'){
				if(abs(int(t2-'A')-int(t4-'A'))==1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else if(t2>='D' && t4>='D'){
				if(abs(int(t2-'A')-int(t4-'A'))==1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000"; 
	}
	else cout<<"0000";
	
	return 0;
}
