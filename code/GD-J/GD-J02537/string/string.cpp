#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string S;
	long long a;
	char c[10001];
	cin>>a>>c[0];
	S = c[0];
	int x = a;
	for(int j=0;j<a-1;j++){
		S += c[0];
	}
	for(int i = 1;i<n;i++){
		cin>>a>>c[i];
		x += a;
		for(int j=0;j<a;j++){
			S += c[i];
		}
	}
	int y = 0;
	for(int i=0;i<(x/2);i++){
		if(S[i] != S[x-1-i]){
			y += 1;
		}
	}
	cout<<y;
	return 0;
}
