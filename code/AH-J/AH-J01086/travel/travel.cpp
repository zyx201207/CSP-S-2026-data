#include<bits/stdc++.h>
using namespace std;
int a,id1,b,id2;
char ch1,ch2;
bool check(char c1,char c2){
	bool f1=false,f2=false;
	if(c1>='A'&&c1<='C'){
		f1=true;
	}
	if(c2>='A'&&c2<='C'){
		f2=true;
	}
	return f1&f2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>id1>>ch1>>b>>id2>>ch2;
	if(a==b) cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(a==b&&id1==id2) cout<<1;
	else cout<<0;
	if(a==b&&id1==id2&&check(ch1,ch2)) cout<<1;
	else{
		cout<<"00"<<endl;
		return 0;
	}
	int num=abs(ch1-ch2)+abs(id1-id2);
	if(num==1) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}
