#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int,int> PII;
bool check1(string ca,string cb,string sa,string sb,bool f){
	if(f==0&&ca!=cb){
		return false;
	}
	if(sa[2]=='A'&&(sb[2]=='D'||sb[2]=='F')){
		return false;
	}
	if(sa[2]=='B'&&(sb[2]=='D'||sb[2]=='F')){
		return false;
	}
	if(sa[2]=='C'&&(sb[2]=='D'||sb[2]=='F')){
		return false;
	}
	if(sa[2]=='D'&&(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')){
		return false;
	}
	if(sa[2]=='F'&&(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')){
		return false;
	}
	return true;
}
bool check2(string ca,string cb,string sa,string sb){
	if(ca!=cb){
		return false;
	}
	if(sa[0]!=sb[0]||sa[1]!=sb[1]){
		return false;
	}
	if(sa[2]=='A'&&sb[2]!='B'){
		return false;
	}
	if(sa[2]=='B'&&(sb[2]!='A'||sb[2]!='C')){
		return false;
	}
	if(sa[2]=='C'&&sb[2]!='B'){
		return false;
	}
	if(sa[2]=='D'&&sb[2]!='F'){
		return false;
	}
	if(sa[2]=='F'&&sb[2]!='D'){
		return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string ca,cb,sa,sb,ans;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		ans+='1';
	}else{
		ans+='0';
	}
	bool flag=0;
	if(sa[0]==sb[0]&&sa[1]==sb[1]&&ca==cb){
		ans+='1';
		flag=1;
	}else{
		ans+='0';
	}
	if(check1(ca,cb,sa,sb,flag)){
		ans+='1';
	}else{
		ans+='0';
	}
	if(check2(ca,cb,sa,sb)){
		ans+='1';
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
}
