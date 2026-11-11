#include<bits/stdc++.h>
using namespace std;
#define int long long
bool tongce(string a,string b){
	char a_zuowei=a[2];
	char b_zuowei=b[2];
	if(a_zuowei=='A'||a_zuowei=='B'||a_zuowei=='C'){
		if(b_zuowei=='A'||b_zuowei=='B'||b_zuowei=='C')return 1;
	}
	else if(a_zuowei=='D'||a_zuowei=='F'){
		if(b_zuowei=='D'||b_zuowei=='F')return 1;
	}
	return 0;
}
bool xiangling(string a,string b){
	if(!tongce(a,b))return 0;
	char a_zuowei=a[2];
	char b_zuowei=b[2];
	if((a_zuowei=='A'&&b_zuowei=='C')||b_zuowei=='A'&&a_zuowei=='C')return 0;
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cR,cX;
	string sR,sX;
	cin>>cR>>sR>>cX>>sX;
	if(cR==cX)cout<<"1";
	else cout<<"0";
	if(cR==cX&&(sR[0]-'0'*10)+(sR[1]-'0')==(sX[0]-'0'*10)+(sX[1]-'0'))cout<<"1";
	else cout<<"0";
	if(cR==cX&&(sR[0]-'0'*10)+(sR[1]-'0')==(sX[0]-'0'*10)+(sX[1]-'0')&&tongce(sR,sX))cout<<"1";
	else cout<<"0";
	if(cR==cX&&(sR[0]-'0'*10)+(sR[1]-'0')==(sX[0]-'0'*10)+(sX[1]-'0')&&xiangling(sR,sX))cout<<"1";
	else cout<<"0";
	return 0;
} 
