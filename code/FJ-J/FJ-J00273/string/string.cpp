#include<bits/stdc++.h>
using namespace std;
long long n,b,jl,l=0;;
string bd;
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char d;
		int s;
		cin>>s>>d;
		b+=s;
		for(long long j=b-s;j<b;j++){
			bd+=d;
		}
	}
	b-=1;
	while(l<b){
		if(bd[l]!=bd[b])jl++;
		l++,b--;
	}
	cout<<jl;
	return 0;
} 
