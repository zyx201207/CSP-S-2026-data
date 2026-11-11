#include<bits/stdc++.h>
using namespace std;
#define int long long
string r1,r2,x1,x2;
bool f1=1,f2=1,f3=1;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	char x3[3]={x2[0],x2[1]},r3[3]={r2[0],r2[1]};
	char x4=x2[2],r4=r2[2];
	if(r1==x1){
		cout << 1;
	}
	else{
		cout << 0;
		f1=0;
	}
	if(f1&&x3[0]==r3[0]&&x3[1]==r3[1]){
	
		cout << 1;
	}
	else{
		cout << 0;
		f2=0;
	}
	if(f2&&((r4=='A'||r4=='B'||r4=='C')&&(x4=='A'||x4=='B'||x4=='C')||(r4=='D'||r4=='F')&&(x4=='D'||x4=='F'))){
		cout << 1;
	}
	else{
		cout << 0;
		f3=0;
	}
	if(f3&&((r4=='D'||r4=='F')&&(x4=='D'||x4=='F'))){
		cout << 1;
	}
	else if(f3&&((!(r4=='A'&&x4=='C'))&&(!(r4=='C'&&x4=='A')))){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	return 0;
} 
