#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
char c[10000005];
string d; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		x+=a[i];	
		for(int j=0;j<a[i];j++){
			d+=c[i];
		}
	} 
	for(int i=0;i<x;i++){
		if(d[i]!=d[x-i-1]){
			s++;
		}
		if(d[i]==d[x-i]||d[i+1]==d[x-i]){
			break;
		}
	}
	cout<<s;
}
