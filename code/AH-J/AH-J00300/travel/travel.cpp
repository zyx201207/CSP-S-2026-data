#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int x1=(s1[0]-'0')*10+s1[1]-'0',x2=(s2[0]-'0')*10+s2[1]-'0';
	//cout<<x1<<" "<<x2<<endl;
	if(x1==x2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>'C'&&s2[2]>'C'||s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((int)s1[2]-(int)s2[2]==1||(int)s1[2]-(int)s2[2]==-1){
		cout<<1;
	}else cout<<0;
	return 0;
}
