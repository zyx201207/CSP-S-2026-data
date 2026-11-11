#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2;
int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cin>>b[i];
		cnt+=i;
	}
	int l=n/2;
	if(n%2==0){
		cout<<l*a[n];
	}if(n%2==1) {
		cout<<l-1;
	}
} 
