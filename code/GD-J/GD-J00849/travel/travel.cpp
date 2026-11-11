#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n,m;
string a1,b1;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		f1=1;
		n+=a1[0]-'0';
		n+=a1[1]-'0';
		m+=b1[0]-'0';
		m+=b1[1]-'0';
		char aid,bid;
		aid=a1[2];
		bid=b1[2];
		if(n==m){
			f2=1;
			if(('A'<=aid&&aid<='C'&&'A'<=bid&&bid<='C')||('D'<=aid&&aid<='F'&&'D'<=bid&&bid<='F')){
				f3=1;
				if(bid==aid+1||bid==aid-1){
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
