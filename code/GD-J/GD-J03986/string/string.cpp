#include <bits/stdc++.h>
using namespace std;

int a[200005];
string c,b,d;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	int x=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			b[x]+=c[i];
			x++;
		}
	}
	for(int i=x-1;i>=0;i--){
		d+=b[i];
	}
	for(int i=0;i<x/2;i++){
		if(b[i]==d[i]){
			continue; 
		}
		else{
			d[i]=b[i];
			cnt++;
		}
	}
	cout<<cnt;
}	
