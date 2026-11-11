#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ssuumm=0;
	cin>>n;
	char c;
	int xsxs;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>xsxs;
		cin>>c;
		for(int j=x;j<x+xsxs;j++){
			s[j]=c;
		}
		x+=xsxs;
	}
	for(int i=0;i<x/2;i++){
		if(s[i]!=s[x-i-1]){
			ssuumm++;
		}
	}
	cout<<ssuumm;
	return 0;
}
