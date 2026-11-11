#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define pll pair<int,int>
string s,ss,t,tt;
int pan(char x){
	if(x>='A'&&x<='C')return 1;
	return 2;
}
bool check_one(){
	if(s==t)return true;
	return false;
}
bool check_two(){
	if(ss[0]==tt[0]&&ss[1]==tt[1])return true;
	return false; 
} 
bool check_three(){
	if(pan(ss[2])==pan(tt[2]))return true;
	return false;
}
bool check_four(){
	char a=min(ss[2],tt[2]),b=max(ss[2],tt[2]);
	if(a=='A'&&b=='B')return true;
	if(a=='B'&&b=='C')return true;
	if(a=='D'&&b=='F')return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>t>>tt;
	if(check_one()){
		cout<<"1";
		if(check_two()){
			cout<<"1";
			if(check_three()){
				cout<<"1";
				if(check_four())cout<<"1";
				else cout<<"0"; 
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

