#include<bits/stdc++.h>
using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long x,s;
	string a="";
	char b;
	cin>>x;
	long long i,j;
	for(i=1;i<=x;i++){
		cin>>s>>b;
		for(j=1;j<=s;j++){
			a=a+b;
		}
	}
	
	
	int c=0;
	for(i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			c++;
		}
	}
	cout<<c;
	
	return 0;
}
