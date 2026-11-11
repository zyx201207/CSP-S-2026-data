#include<bits/stdc++.h>
using namespace std;
long long a[200020];
char b[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(b[i]!=b[n+1-i]){
			ans+=min(a[i],a[n+1-i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
