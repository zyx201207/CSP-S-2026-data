#include<bits/stdc++.h>
using namespace std;
string b;
int n,a;
int hws(string x){
	int c=0;
	for(long long i=0;i<=x.size()/2;i++){
		if(x[i]!=x[x.size()-i-1]){
			c++;
		}
	}
	return c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		string c;
		cin>>c;
		for(int j=1;j<=a;j++){
			b+=c;
		}
	}
	cout<<b;
	cout<<hws(b);
	return 0;
}
