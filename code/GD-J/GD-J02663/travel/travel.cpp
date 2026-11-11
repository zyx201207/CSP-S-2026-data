#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
char ans;
int a1=0,a2=0,a3=0,a4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	for(int i=0;i<c1.size();i++)a1=a1*10+(c1[i]-'0');
	for(int i=0;i<c3.size();i++)a2=a2*10+(c3[i]-'0');
	if(a1!=a2){
		ans='0';
		for(int i=1;i<=4;i++)cout<<ans;
		return 0;
	}else{
		ans='1';
		cout<<ans;
	}
	for(int i=0;i<c2.size()-1;i++)a3=a3*10+(c2[i]-'0');
	for(int i=0;i<c4.size()-1;i++)a4=a4*10+(c4[i]-'0');
	if(a3!=a4){
		ans='0';
		for(int i=1;i<=3;i++)cout<<ans;
		return 0;
	}else{
		ans='1';
		cout<<ans;
	}
	char x1=c2[c2.size()-1],x2=c4[c4.size()-1];
	if((x1>='D'&&x2<='C')||(x2>='D'&&x1<='C')){
		ans='0';
		for(int i=1;i<=2;i++)cout<<ans;
		return 0;
	}else{
		ans='1';
		cout<<ans;
	}
	if(x1+1==x2||x1-1==x2){
		ans='1';
		cout<<ans;
		return 0;
	}else{
		ans='0';
		cout<<ans;
	}
	return 0;
}
