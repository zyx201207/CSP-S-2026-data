#include<bits/stdc++.h>
using namespace std;
long long a;
long long k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>a;
	long long s[a-1];
	char d[a-1];
	for(int i=0;i<a;i++){
		cin>>s[i];
		cin>>d[i];
	}
	for(int i=0;i<a/2;i++){
		if(d[i]!=d[a-1-i]){
			k=k+s[i];
		}
	}
	cout<<k;
	return 0;
}
