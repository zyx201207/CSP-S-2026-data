#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
char c,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>c;
		if(c>='0'&&c<='9') a1=a1*10+(c-'0');
		else s1=c;
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>c;
		if(c>='0'&&c<='9') a2=a2*10+(c-'0');
		else s2=c;
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a1!=a2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(s1<='C'&&s2>='D'||s2<='C'&&s1>='D'){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s1=='A'&&s2=='B'||s2=='A'&&s1=='B'||s1=='C'&&s2=='B'||s2=='C'&&s1=='B'||s1=='D'&&s2=='F'||s1=='F'&&s2=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
