#include<bits/stdc++.h>
#define int long long 
using namespace std;
string r1,r2,x1,x2;
bool flag1=0,flag2=0,flag=1;
void solve(){
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
	} else {
		cout<<"0000";
		return;
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1]){
		cout<<1;
		flag1=1;
	} else {
		cout<<0;
	}
	if((r2[2]=='C'&&x2[2]=='D')||(r2[2]=='D'&&x2[2]=='C')){
		flag=0;
		cout<<0;
	} else if(flag1&&(((r2[2]=='F'||r2[2]=='D')&&(x2[2]=='F'||x2[2]=='D')) || ((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')||(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')))){
		cout<<1;
		flag2=1;
	} else {
		cout<<0;
	}
	
	string a=r2,b=x2;
	int c=(a[0]-'0')*10+(a[1]-'0');
	int d=(b[0]-'0')*10+(b[1]-'0');
	if((!flag1)&&(!flag2)){
		cout<<0;
		return;
	}
	if(flag&&(abs(a[2]-b[2])==0&&(abs(c-d)==1))){
		cout<<1;
		return;
	} 
	if(flag&&(abs(a[2]-b[2])==1&&(c==d))){
		cout<<1;
		return;
	}
	cout<<0;
	
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

