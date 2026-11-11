#include<bits/stdc++.h>
using namespace std;
string s,s1;
string c,c1;
int a[5];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>c;
	cin>>s1>>c1;
	if(s1==s){
		a[1]=1;
	}else{
		cout<<"0000";
		return 0;
	}
	string ss=c;
	string ss1=c1;
	ss[2]='1';
	ss1[2]='1';
	//cout<<ss<<" "<<ss1<<" ";
	if(ss==ss1){
		a[2]=1;
	}else{
		cout<<"1000";
		return 0;
	}
	char w=c[2],w1=c1[2];
	int x=int(w-'A'),y=int(w1-'A');
	if((w<='C' && w1<='C') || (w>'C' && w1>'C')){
		a[3]=1;
	}
	if(abs(x-y)==1 && a[3]==1){
		a[4]=1;
	}
	//cout<<x<<" "<<y<<" "; 
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
} 
/*
02 01C 02 01A

Trick||Treat!
*/
