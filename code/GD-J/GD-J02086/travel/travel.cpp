#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int cnt[N]={1,2,3,4,5,6,7,8};
string a,a1,b,b1;
int check(int x,int y){
	if(x<=3&&y<=3){
		if(abs(x-y)==1){
			return 2;
		}
		return 1;
	}else if(x>3&&y>3){
		return 2;
	}
	return -1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>a1>>a>>b1>>b;
	//x1³µÏá   xÎ»ÖÃ
	for(int i=0;i<2;i++){
		if(a1[i]!=b1[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	int x=cnt[a[2]-'A'];
	int y=cnt[b[2]-'A'];
	int c=check(x,y);
	if(c==-1){
		cout<<"00";
	}else{
		cout<<"1";
		if(c==2){
			cout<<"1";
			return 0;
		}
		cout<<"0"; 
	}
	return 0;
}
