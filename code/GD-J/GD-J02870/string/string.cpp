#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int long long n;
int long long  a,ans;
char c;
string k;
bool u=true; int long long  sum;
void w( int long long  x,char y){
	for(int i=0;i<x;i++){
			k+=y;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int long long i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		w(a,c);
	}
	for( int long long i=0;i<sum/2;i++){
		if(k[i]!=k[sum-i-1]){
		ans++;
		}
	cout<<ans;}
	return 0;
		
}
