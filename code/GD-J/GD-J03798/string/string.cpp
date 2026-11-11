#include<bits/stdc++.h>
using namespace std;
string S;
long n,a[1005];
char c[1005];
int huiwen(){
	int size=0,x=0;
	for(int i=0;i<n;i++){
		size=size+a[i];
	}
	for(int j=0;j<size/2;j++){
		if(S[j]==S[size-j-1]){
			continue;
		}
		x++;
	}
	return x;
}
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			S=S+c[i];
		}
	}
	cout<<huiwen();
	return 0;
}
