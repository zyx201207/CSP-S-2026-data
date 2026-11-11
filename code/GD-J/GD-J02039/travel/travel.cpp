#include<bits/stdc++.h>
using namespace std;
string s1,s2,x1,x2;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>s1>>s2>>x1>>x2;
	if(s1!=x1){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<1;
	int h1=(s2[0]-'0')*10+(s2[1]-'0'),h2=(x2[0]-'0')*10+(x2[1]-'0');
	if(h1!=h2){
		cout<<"000"<<endl;
		return 0;
	}
	cout<<1;
	if(s2[2]=='C'&&x2[2]=='D'||s2[2]=='D'&&x2[2]=='C'){
		cout<<"00"<<endl;
		return 0;
	}
	cout<<1;
	if(s2[2]==x2[2]+1||s2[2]==x2[2]-1){
		cout<<1<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
