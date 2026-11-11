#include<bits/stdc++.h>
using namespace std;
long long n,a[20005],l;
char c[30];
int pd=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]&&i>1) pd++;
		l+=a[i];
	}
	if(pd==n-1) cout<<0;
	if(a[1]==l/2){
		cout<<l/2;
	}
	return 0;
}
