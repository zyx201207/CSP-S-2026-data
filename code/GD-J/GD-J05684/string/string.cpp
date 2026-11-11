#include <bits/stdc++.h>
using namespace std;
long long n,a,ll,qwq,ii;
char c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(int j=0;j<a;j++){
			s[ii]=c;
			ii++;
		}
		ll+=a;
	}
	for(int i=0;i<ll;i++){
		if(s[ll-1-i]!=s[i]) {
			qwq++;
		}
	}
	cout<<qwq;
	return 0;
}
