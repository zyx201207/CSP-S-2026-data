#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,k,a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000)	cout<<n;return 0;
	int c=0;
	for(int i=1;i<=n;i++){
		if(c>=k){
			cout<<i-1;
			return 0;
		}
		c+=i; 
	}
	return 0;
}
