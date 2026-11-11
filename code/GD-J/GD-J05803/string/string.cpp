#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,cnt=0;;
	cin>>a;
	string b,d[a];
	long long c[a];
	for(long long i=0;i<a;i++){
		cin>>c[i]>>d[i];
		for(long long j=0;j<c[i];j++){
			b+=d[i];
		}
	}
	for(long long i=0;i<b.length()/2 + b.length()%2;i++){
		if(b[i]!=b[b.length()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
