#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int c1,c2,se1,se2;
string s1,s2;
bool flag;
void q1(){
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
}
void q2(){
	se1=(s1[0]-'0')*10+(s1[1]-'0');
	se2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1!=c2){
		cout<<0;
		return;
	}
	if(se1==se2){
		cout<<1;
	}else{
		cout<<0;
	}
}
void q3(){
	if(c1!=c2){
		cout<<0;
		flag=false;
		return;
	}
	if(se1==se2){
		if((s1[2]>='D' && s2[2]>='D') || (s1[2]<='C' && s2[2]<='C')){
			cout<<1;
			flag=true;
		}else{
			flag=false;
		}
	}else{
		flag=false;
		cout<<0;
	}
}
void q4(){
	if(flag){
		if(abs((int)s1[2]-(int)s2[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0<<endl;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	q1();
	q2();
	q3();
	q4();
	return 0;
}

