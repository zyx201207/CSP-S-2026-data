#include <bits/stdc++.h>
using namespace std;
char a[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,l=1;
	char s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>s;
		for(int i=l;i<=l-1+m;i++){
			a[i]=s;
		}
		l=l+m;
	}
	long long c=0,t=l-m;
	for(int i=1;i<=t/2;i++){
		if(a[i]!=a[t-i+1]){
			c++;
		}
	}
	cout<<c;
	return 0;
}
