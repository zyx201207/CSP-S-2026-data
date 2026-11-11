#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	string s="";
	int ss=0;
	for(int i=1;i<=n;i++){
		int m;
		char k;
		cin>>m>>k;
		ss+=m;
		for(int i=1;i<=m;i++){
			s+=k;
		}
	}
	int L=0,R=ss-1;
	int f=0;
	while(L<R){
		if(s[L]!=s[R]){
			f++;
		}
		L++,R--;
	}
	cout<<f;
	return 0;
}
