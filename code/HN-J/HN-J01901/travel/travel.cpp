#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	if(c1==c2){
		cout<<"1";
		f++;
	}else{
		cout<<"0";
	}
	
	char t1=s1[2];
	char t2=s2[2];
	if(f==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		f++;
	}else{
		cout<<0;
	}
	
	if(f==2&&((t1<='C'&&t2<='C')||(t1>='D'&&t2>='D'))){
		cout<<"1";
		f++;
	}else{
		cout<<0;
	}
	
	if(f==3&&(abs(int(t1-t2))==1||(t1=='D'&&t2=='F')||(t2=='D'&&t1=='F'))){
		cout<<"1";
	}else{
		cout<<0;
	}
	return 0;
}

