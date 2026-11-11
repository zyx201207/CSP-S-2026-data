#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int an[N];
char bn[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int zypc=0,sdfz,mdtx=0;
	for(int i=1;i<=n;i++){
		cin>>an[i];
		cin>>bn[i];
	}
	for(int i=0;i<=n-1;i++){
		if(bn[i]==bn[i+1])sdfz=1;
		else{
			sdfz=0;
			continue;
		} 
	}
	if(sdfz==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		zypc+=an[i];
	}
	if(zypc%2!=0){
		cout <<zypc/2;
		return 0;
	}
	return 0;
} 
