#include<bits/stdc++.h>
using namespace std;
string st;
char c;
long long b,n,sum,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		sum+=b;
		for(int j=1;j<=b;j++){
			st+=c;
		}
	}
	for(int i=0;i<sum/2;i++){
		if(st[i]!=st[sum-i-1])s++;
	}
	cout<<s;
	return 0;
}
