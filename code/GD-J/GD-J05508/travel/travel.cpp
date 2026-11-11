#include<bits/stdc++.h>
using namespace std;
bool fl1,fl2,fl3,fl4;
string c1,s1,c2,s2;
int b1,b2,st1,st2;
char ch1,ch2;
bool check1(char x,char y){
	if((x>='A'&&x<='C')&&(y>='A'&&y<='C')) return true;
	if((x=='D'||x=='F')&&(y=='D'||y=='F')) return true;
	return false;
}
bool check2(int x,int y){
	if((x=='D'||x=='F')&&(y=='D'||y=='F')) return true;
	if(abs((int)x-(int)y)==1) return true;
	return false;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=c1.size()-1;i>=0;i--) b1=b1*10+(c1[i]-'0');
	for(int i=c2.size()-1;i>=0;i--) b2=b2*10+(c2[i]-'0');
	for(int i=s1.size()-2;i>=0;i--) st1=st1*10+(s1[i]-'0');
	for(int i=s2.size()-2;i>=0;i--) st2=st2*10+(s2[i]-'0');
	ch1=s1[s1.size()-1];ch2=s2[s2.size()-1];
	if(b1==b2) fl1=true;
	if(fl1&&st1==st2) fl2=true;
	if(fl2&&check1(ch1,ch2)) fl3=true;
	if(fl3&&check2(ch1,ch2)) fl4=true;
	cout<<fl1<<fl2<<fl3<<fl4<<'\n';
	return 0;
}
