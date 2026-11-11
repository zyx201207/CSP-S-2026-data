#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
map<pair<char,char>,bool> p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	p[{'F','D'}]=true;
	p[{'D','F'}]=true;
	if(c1==c2){
		cout<<1;
		string a=s1.substr(0,2),b=s2.substr(0,2);
//		cout<<a<<" "<<b<<"\n";
		char x=s1[2],y=s2[2];
		if(a==b){
			cout<<1;
			if(p[{x,y}]){
				cout<<"11"<<"\n";
			}
			else if(x>='A' && x<='C' && y>='A' && y<='C'){
				cout<<1;
				if(abs(x-y)==1){
					cout<<1<<"\n";
				}
				else{
					cout<<0<<"\n";
				}
			}
			else{
				cout<<"00"<<"\n";
			}
		}
		else{
			cout<<"000"<<"\n";
		}
	}
	else{
		cout<<"0000"<<"\n";
	}
	return 0;
}
