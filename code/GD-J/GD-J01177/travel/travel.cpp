#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string x,r;
	cin>>n>>x>>m>>r;
	int X=(x[0]-'0')*10+x[1]-'0';
	int R=(r[0]-'0')*10+r[1]-'0';
	if(n==m){
		cout<<"1";
		if(X==R){
			cout<<"1";
			if(x[2]=='A'||x[2]=='B'||x[2]=='C'){
				if(r[2]=='A'||r[2]=='B'||r[2]=='C'){
					cout<<"1";
					if(x[2]>r[2])swap(x[2],r[2]);
					if(x[2]=='A'&&r[2]=='B')cout<<"1";
					else if(x[2]=='B'&&r[2]=='C')cout<<"1";
					else cout<<"0";
				}else{
					cout<<"00";
				}
			}else{
				if(r[2]=='D'||r[2]=='E'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
