#include<bits/stdc++.h>
using namespace std; 
const long long N=2e5+5;
long long n,m,x,y,z,op,sum,t,k,a[N],b[N],f[N],flag,js,ans;
string rcx,rzw,xcx,xzw;
void solve(){
	cin>>rcx>>rzw>>xcx>>xzw;
	if(rcx==xcx){
		cout<<"1";
		if((rzw[0]==xzw[0])&&(rzw[1]==xzw[1])){
			cout<<"1";
			if((rzw[2]=='F'&&xzw[2]=='D')||(rzw[2]=='D'&&xzw[2]=='F')||(rzw[2]=='C'&&xzw[2]=='B')||(rzw[2]=='C'&&xzw[2]=='A')||(rzw[2]=='B'&&xzw[2]=='C')||(rzw[2]=='B'&&xzw[2]=='A')||(rzw[2]=='A'&&xzw[2]=='C')||(rzw[2]=='A'&&xzw[2]=='B')){
				cout<<"1";
				if((rzw[2]=='F'&&xzw[2]=='D')||(rzw[2]=='D'&&xzw[2]=='F')||(rzw[2]=='C'&&xzw[2]=='B')||(rzw[2]=='B'&&xzw[2]=='C')||(rzw[2]=='B'&&xzw[2]=='A')||(rzw[2]=='A'&&xzw[2]=='B'))
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel2.in","r",stdin);
//	freopen("travel2.out","w",stdout);
//	freopen("travel3.in","r",stdin);
//	freopen("travel3.out","w",stdout);
//	freopen("travel4.in","r",stdin);
//	freopen("travel4.out","w",stdout);
//	freopen("travel5.in","r",stdin);
//	freopen("travel5.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
