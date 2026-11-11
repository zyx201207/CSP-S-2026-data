#include <bits/stdc++.h>
using namespace std;
//struct node{
//	
//};
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//int dis[100001];
string input1,input2;
string tmp1,tmp2;
int a,b,c,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>tmp1;
	cin>>input1;
	cin>>tmp2;
	cin>>input2;
	int num1=0,num2=0;
	num1+=(int) input1[1]-'0';
	num1+=((int) input1[0]-'0')*10;
	num2+=(int) input2[1]-'0';
	num2+=((int) input2[0]-'0')*10;
	if(tmp1==tmp2){
		a=1;
	}
	if(a && num1==num2){
		b=1;
	}
	if(b && input1[2]<='C' && input2[2]<='C'){
		c=1;
	}
	if(b && input1[2]>='D' && input2[2]>='D'){
		c=1;
	}
	if(c && (input1[2]-input2[2]==1 || input1[2]-input2[2]==-1)){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
