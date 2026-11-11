#include <bits/stdc++.h>
using namespace std;
long long q,w,e;
char a,b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>q;
	if(q==1){
		cout<<0;
		return 0;
	}
	cin>>w>>a>>e>>b;
	if(a==b){
		cout<<0;
		return 0;
	}else{
		cout<<min(w,e);
	}
	return 0;
}
