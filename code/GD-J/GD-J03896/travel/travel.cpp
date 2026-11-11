#include<bits/stdc++.h>
using namespace std;
int fgh(string a1,string b1){
	int gyh = 1;
	for(int i = 0;i<a1.size();i++){
		if(a1[i]!=b1[i])gyh = 0;
	}
	return gyh;
}
int fgh2(string a2,string b2){
	int gyh2 = 1;
	for(int i2 = 0;i2<a2.size()-1;i2++){
		if(a2[i2]!=b2[i2])gyh2 = 0;
	}
	return gyh2;
}
int qwe(string aw,string bc){
	
	int f,g;
	if(aw[2] == 'F' or aw[2]=='D')f = 10;
	else f = 20;
	if(bc[2] == 'F' or bc[2]=='D')g = 10;
	else g = 20;
	if(f == g)return 1;
	else return 0;
	
	
}
int ghk(char a4,char b4){
	int uio = 0;
	if(a4=='F' and b4=='D')uio = 1;
	if(a4=='D' and b4=='F')uio = 1;
	if(a4=='C' and b4=='B')uio = 1;
	if(a4=='B' and b4=='C')uio = 1;
	if(a4=='B' and b4=='A')uio = 1;
	if(a4=='A' and b4=='B')uio = 1;
	return uio;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	int hj = 0;
	if(hj==0 and fgh(a,d)==1){
		cout<<1;
	}
	else{
		hj++;
		cout<<0;
	} 
	if(hj==0 and fgh2(s,f)==1){
		cout<<1;
	}
	else{
		hj++;
		cout<<0;
	}
	if(hj==0 and qwe(s,f)==1)cout<<1;
	else{
		hj++;
		cout<<0;
	}
	if(hj == 0 and ghk(s[2],f[2])==1)cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
} 
