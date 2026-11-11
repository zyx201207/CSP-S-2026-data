#include <bits/stdc++.h>
using namespace std;
string b,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,cnt=0;
	cin>>n;
	if(n==1){
		long long m;
		string c;
		cin>>m>>c;
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long m;
		string c;
		cin>>m>>c;
		while(m--){
			b +=c;
		}
	}
	for(int i=b.size()-1;i>=0;i--){
		x +=b[i];
	}
	if(b==x){
		cout<<0;
	}
	return 0;
} 
