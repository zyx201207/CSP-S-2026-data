#include<bits/stdc++.h>
using namespace std;
int n,a;
string b,last;
string entire;
bool flag=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(last!=b&&i!=1) flag=0;
		for(int j=1;j<=a;j++)
			entire+=b;
		last=b;
	}
	long long l=entire.size();
	bool tf=1;
	for(int i=0;i<l;i++){
		if(entire[i]!=entire[l-i]) tf=0;
	}
	if(flag) cout<<0;
	else if(tf) cout<<0;
	return 0;
}
