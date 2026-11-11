#include <bits/stdc++.h>
using namespace std;
long long a,b;
char c;
char s[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	long long ss=1;
	for(int i=1;i<=a;i++){
		cin>>b>>c;
		if(b>=1000000000) b/=100000	;
		for(int i=1;i<=b;i++){
			s[ss]=c;
			ss++;
		}
	}
	long long ans;
	ss--;
	for(int i=1;i<=ss;i++){
		if(s[i]!=s[ss--]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
