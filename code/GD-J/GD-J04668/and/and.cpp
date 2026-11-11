#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
long long n,m;
long long a[N],b[N];
void ccp(long long x){
	int ans=1;
	while(a[x]!=0){
		ans*=10;
		b[x]+=a[x]%2*ans;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i];
	} 
	cout<<a[1];
	return 0; 
}
