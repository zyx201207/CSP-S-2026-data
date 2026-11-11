#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e5+10;
int a1,a2,b1,b2;
char a3,b3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	if(a1==b1) {
		cout<<1;
		if(a2==b2){
			cout<<1;
			bool st=0;
			if(a3>='A'&&a3<='C'&&b3>='A'&&b3<='C') st=1;
			if(a3>='D'&&a3<='F'&&b3>='D'&&b3<='F') st=1;
			if(st==1){
				cout<<1;
				if(a3+1==b3||b3+1==a3) cout<<1;
				else cout<<"0";
			}
			else cout<<"00"; 
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
