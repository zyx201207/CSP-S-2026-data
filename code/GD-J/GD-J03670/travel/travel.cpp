#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen('travel.in','r',stdin);
	freopen('travel.out','w',stdout);
	string a,b,c,d,ans='';
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+='1';
		if(b[0]==d[0] and b[1]==d[1]){
			ans+='1';
			
			bool zuo1=false,zuo2=false;
			if((b[2]!='D' ) && (b[2]!='D'))zuo1=true;
			if(d[2]!='D' && d[2]!='F')zuo2=true;
			if(zuo1==zuo2){
				ans+='1';
				int id=0,id2=0;
				if(abs((int)d[2]-b[2])==1)ans+='1';
				else ans='1110';
			}else{
				ans='1100';
			}
		}else{
			ans='1000';
		}
	}else{
		ans='0000';
	}
	cout<<ans;
} 
