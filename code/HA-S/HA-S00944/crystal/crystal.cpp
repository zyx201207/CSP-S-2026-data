#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long cha=b[2]-b[1];
	for(int i=1;i<=n;i++){
		a[i]=i-1+a[i-1];
	}
	
	for(int i=1;i<=n;i++){
		if(m>=cha*a[i]&&m<cha*a[i+1]){
			cout<<i;
		}
		if(i==n&&m>cha*a[i]){
			cout<<n;
		}
	}
	return 0;
}

