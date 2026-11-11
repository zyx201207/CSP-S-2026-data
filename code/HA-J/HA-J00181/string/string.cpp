#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
char d;
string e,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>d;
		for(int j=0;j<b;j++){
			e+=d;
		}
	}
	for(int i=0;i<e.length();i++){
		if(e[i]!=e[e.length()-1-i]){
			c++;
		}
	}
	cout<<c/2;
	return 0;
} 
