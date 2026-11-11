//GZ-J00658 陈泓澍 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
string a,b,m,n;//65-70 no 69
int num=1;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout); 
	cin>>a>>m>>b>>n;
	if(a!=b){
		cout<<"0000";
		num--;
		return 0;
	}
	if(m[0]==n[0] && m[1]==n[1]) num++;
	if((m[2]>=65 && m[2]<=67 && n[2]>=65 && n[2]<=67) && num==2) num++;
	if((n[2]=='D' && m[2]=='F' || n[2]=='D' && m[2]=='F') && num==2){
		cout<<"1111";
		num--;
		return 0;
	}	
	if((n[2]<='C'&&n[2]>='c'&&m[2]>='D'&&m[2]<='F' || n[2]>='D'&&n[2]<='F'&&m[2]<='C'&&m[2]>='A')&&num==2){
		cout<<"1100";
		num--;
		return 0;
	}
	if(num==3){
		if(num==3 &&(n[2]=='A'&&m[2]=='B' || n[2]=='B'&&m[2]=='C' || n[2]=='C'&&m[2]=='B' ||n[2]=='B'&&m[2]=='A')){
			cout<<"1111";
			num++;
			return 0;
		}
		if((n[2]-m[2]!=-1)||(n[2]-m[2]!=1)){
			cout<<"1110";
			num--;
			return 0;
		}
		 
	}
	if(num==1) cout<<"1000";return 0;
	if(num==2) cout<<"1100";return 0;
	cout<<num;
	return 0;
}
