#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[10],s2[10];
bool f(char x){
	if(x=='A'||x=='B'||x=='C'){
		return 1;
	}else{
		return 0;
	}
}
void S(){
	cin>>c1>>s1+1>>c2>>s2+1;
	//cout<<c1<<endl<<c2<<endl<<s1+1<<endl<<s2+1<<endl;
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<"1";
			if(f(s1[3])==f(s2[3])){
				cout<<"1";
				if(abs(s1[3]-s2[3])==1){
					cout<<"1";
				}else{
					cout<<"0";
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
	cout<<endl;
	return;
}
int main(){
	//T1
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) S();
	return 0;
}
