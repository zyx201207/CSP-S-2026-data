#include<bits/stdc++.h>
using namespace std;
bool ce(char x,char y){
	if(x=='F'){
		return y=='D';
	}
	if(x=='D'){
		return y=='F';
	}
	if(x=='C'){
		return y=='B'||y=='A';
	}
	if(x=='B'){
		return y=='C'||y=='A';
	}
	if(x=='A'){
		return y=='B'||y=='C';
	}
}
bool lin(char x,char y){
	if(x=='F'){
		return y=='D';
	}
	if(x=='D'){
		return y=='F';
	}
	if(x=='C'){
		return y=='B';
	}
	if(x=='B'){
		return y=='C'||y=='A';
	}
	if(x=='A'){
		return y=='B';
	}
}
string ans;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
//	cout<<c1<<"\n"<<s1<<"\n"<<c2<<"\n"<<s2<<"\n";
	if(c1==c2){
		ans+='1';
	}else{
		ans+='0';
	}
	if(ans[0]=='1'&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+='1';
	}else{
		ans+='0';
	}
	if(ans[1]=='1'&&ce(s1[2],s2[2])){
		ans+='1';
	}else{
		ans+='0';
	}
	if(ans[2]=='1'&&lin(s1[2],s2[2])){
		ans+='1';
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
}
