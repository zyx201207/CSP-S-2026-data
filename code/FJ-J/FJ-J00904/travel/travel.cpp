#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	string a,b;//票 
	string x,y;//车厢 
	cin>>x>>a>>y>>b;
	int che1=(x[0]-'0')*10+(x[1]-'0');//车厢编号 1
	int che2=(y[0]-'0')*10+(y[1]-'0');//车厢编号 2
	int c=(a[0]-'0')*10+(a[1]-'0');//数字排号  c
	int d=(b[0]-'0')*10+(b[1]-'0');//数字排号  d
	char e=a[2],f=b[2];//座位字符 
	
	if(che1==che2){
		cout<<1;
		if(c==d){
			cout<<1;
			if( (e<='C' && f<='C') || (e>'C' && f>'C') ){
				cout<<1;
				if(abs(e-f)==1){
					cout<<1;
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
	//cout<<abs(e-f)<<endl<<e<<"   "<<f;
	return 0;
} 
//谁言天公不好客 漫天风雪送一人 
