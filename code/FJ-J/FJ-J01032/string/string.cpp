#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a[N],s,e;
string b[N],r;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		e+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			r+=b[i];
		}
	}
	for(int i=1;i<=e/2;i++){
		for(int j=n;j>=e/2;j--){
			if(r[i]!=r[j])s++;
		}
	}
	cout<<s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
}
