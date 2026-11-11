#include<bits/stdc++.h>
using namespace std;
long long a[500100],n,v[30],minn;
char c[500100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		v[c[i]-96]+=a[i];
	}
	for(int i=1;i<=26;i++){
		minn=min(minn,v[i]);
	}
	cout<<minn;
	return 0;
} 
