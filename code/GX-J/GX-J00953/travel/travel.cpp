#include<iostream>
#include<string>
#define team return 
#define spirit 0
using namespace std;
int c1,c2;//number
string s1,s2;//set
void IF(){
	if((s1[2]=='F'&&s2[2]=='D') || (s2[2]=='F'&&s1[2]=='D'))cout<<1;
	else if( (s1[2]=='C'&&s2[2]=='B') || (s1[2]=='B'&&s2[2]=='A') || (s2[2]=='C'&&s1[2]=='B') || (s2[2]=='B'&&s1[2]=='A') )cout << 1;
	else cout<<0;
}
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout << 1;
			if(s1[2]=='F'||s1[2]=='D'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<1;
					IF();
				}
				else {
					cout<<"00";
					team spirit;
				}
			}
			else if((s1[2]=='A'||s1[2]=='B')||s1[2]=='C'){
				if(s2[2]!='F'&&s2[2]!='D'){
					cout<<1;
					IF();
				}
				else {
					cout<<"00";
					team spirit;
				}
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	
	//9:41 AC T1
	team spirit;
}
