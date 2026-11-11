#include<iostream>
#include<algorithm>
using std::cin;
using std::cout;
int c1,c2;
std::string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			std::string sp;sp+=s1[2];sp+=s2[2];
			std::sort(sp.begin(),sp.end());
			if((sp[0]<'D'&&sp[1]<'D')||(sp[0]>='D'&&sp[1]>='D')){
				cout<<1;
				if(sp=="AB"||sp=="BC"||sp=="DF"){
					cout<<1;
					//I all failed IOI!!!!!!!!
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
}
