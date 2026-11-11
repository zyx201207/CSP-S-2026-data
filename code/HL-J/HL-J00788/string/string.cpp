#include <bits/stdc++.h>
using namespace std;
int S[100000];
int a[100000];
int c[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,L;cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]=a[i+1];
		c[i]=c[i+1];
	}
	for(int i = 1;i<=L;i++){
		S[i]=S[L+1-i];
	}
	for(int i = S[L];i>=1;i--){
		if(S[i]>=S[i-1]){
			cout<<S[i-1];
		}
	}
	return 0;
}
