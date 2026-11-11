#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
string str,st,str1,st1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>str>>st>>str1>>st1;
	if(str==str1){
		cout<<1;
		if(st[0]==st1[0]&&st[1]==st1[1]){
			cout<<1;
			if(st[2]=='A'&&st1[2]=='B'){
				cout<<11;
			}else if(st[2]=='B'&&st1[2]=='C'){
				cout<<11;
			}else if(st[2]=='D'&&st1[2]=='E'){
				cout<<11;
			}else if(st[2]=='B'&&st1[2]=='A'){
				cout<<11;
			}else if(st[2]=='C'&&st1[2]=='B'){
				cout<<11;
			}else if(st[2]=='E'&&st1[2]=='D'){
				cout<<11;
			}else if(st[2]=='A'&&st1[2]=='C'){
				cout<<10;
			}else if(st[2]=='C'&&st1[2]=='A'){
				cout<<10;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
