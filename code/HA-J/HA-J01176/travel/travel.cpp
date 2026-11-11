#include<bits/stdc++.h>
using namespace std;
string n;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		n+='1';
		bool k=0;
		if(b[0]==d[0]&&b[1]==d[1]){
			n+='1';
			if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
				k=1;
			}
		}else{
			n+='0';
		}
		if(k==1){
			n+='1';
		}else{
			n+='0';
		}
		int x=(b[0]-'0')*10+(b[1]-'0');
		int y=(d[0]-'0')*10+(d[1]-'0');
		if(x-y==1&&b[2]==d[2]||y-x==1&&b[2]==d[2]||y==x&&b[2]-d[2]==1||y==x&&d[2]-b[2]==1){
		if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
			n+='1';
		}else{
			n+='0';
		}
		
		}else{
			n+='0';
		}
		
	}else{
		cout<<"0000";
		return 0;
	}
	cout<<n;
	return 0;
}
