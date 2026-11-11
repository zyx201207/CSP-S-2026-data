#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,o=0;
	int a,b;
	string a1 ,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		o=1;
		cout<<0;
	}
	if(o==0&&a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<1;
	}else{
		cout<<0;
		o=1;
	}
	if(a1[2]>='D'&&b1[2]>='D'&&o==0||a1[2]<='C'&&b1[2]<='C'&&o==0){
		cout<<1;
	}else{
		cout<<0;
		o=1;
	}
	if(o==0&&a1[2]==b1[2]+1||o==0&&a1[2]==b1[2]-1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
