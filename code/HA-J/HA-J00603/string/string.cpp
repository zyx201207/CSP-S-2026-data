#include<bits/stdc++.h>
using namespace std;
string b[100000005];
int d[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,f=0;
	
	cin>>n;
	string c;
	for(int i=0;i<n;i++){
		cin>>d[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<d[i];j++){
			c=c+b[i];
		}
	}
	int h=c.length();
	for(int i=0;i<h/2;i++){
		if(c[i]!=c[h-i-1]){
			f++;
		}
	}
	cout<<f;
	return 0;
}
