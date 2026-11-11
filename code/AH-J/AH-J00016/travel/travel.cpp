#include<iostream>
using namespace std;
bool check(char a,char b){
	if(a=='A') return (b=='B');
	if(a=='B') return (b=='A'||b=='C');
	if(a=='C') return (b=='B');
	if(a=='D') return (b=='F');
	return (b=='D');
}
	int t[1000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	t['A']=t['B']=t['C']=1;
	t['D']=t['F']=2;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(t[b[2]]==t[d[2]]){
				cout<<"1";
				if(check(b[2],d[2])){
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
}
