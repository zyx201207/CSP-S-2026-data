#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s, w={};
	cin >> s;
	int l=s.length(), y=0;;
	for(int i=0;i<l/2;i++){
		w=s[i]+w;
	}
	for(int i=(i+1)/2+1;i<l;i++){
		if(s[i]!=w[i]){
			y++;
		}
	}
	cout << y;
	return 0;
}
