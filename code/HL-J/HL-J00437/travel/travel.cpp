#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int m1,m2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			m1=b[2]-'A';
			m2=d[2]-'A';
			if((m1<3&&m2<3)||(m1>=3&&m2>=3)){
				if(m1==m2-1||m1==m2+1){
					cout<<"1111";
				}else cout<<"1110";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
