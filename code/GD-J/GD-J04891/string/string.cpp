#include<bits/stdc++.h>
using namespace std;
	long long n=0,m[1000000]={0},o;
	string a[100000],b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>o;
	for(int i=0;i<o;i++){
		cin>>m[i]>>a[i];
	}	
	for(int i=0;i*2<o;i++){
		if(a[i]!=a[o-i-1]){
			n+=m[i];
		}	
	}	
	cout<<n;
	return 0;
} 

