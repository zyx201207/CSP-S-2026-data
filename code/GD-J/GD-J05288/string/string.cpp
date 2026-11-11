#include<bits/stdc++.h>
using namespace std;

string s="";
int huiwen(string p){
	int x=0,y;
	y=p.length();
	string h[y+1];
	for(int i=1;i<=y/2;i++){
		h[i]=p.substr(i-1,1);
		h[y-i+1]=p.substr(y-i,1);
		if(h[i] != h[y-i+1]) x++;
	}
	return x;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	string c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	cout<<huiwen(s);
	
	return 0;
}
