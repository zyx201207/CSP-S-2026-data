#include<iostream>
#include<string>
using namespace std;
string a,b,c,d;
int s[6]={1,2,3,5,0,6};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int m=b[2]-'A';
			int n=d[2]-'A';
			m=s[m];
			n=s[n];
			if((m>=5&&n>=5)||(m<5&&n<5)){
				cout<<1;
				if(m-n==1||m-n==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
