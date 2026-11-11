#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,k=0;
	while(l<r){
		long long m=min(a[l],a[r]);
		if(c[l]!=c[r]){
			k+=m;
		}
		a[l]-=m;
		a[r]-=m;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<k;
}
