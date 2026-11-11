#include<bits/stdc++.h>
using namespace std;
struct st{
	int x;
	char c;
}a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,f=0;
	cin>>n;
	long long ans=0,k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	if(n==1){cout<<0;return 0;}
	if(n==2){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[i].c!=a[j].c)f=1;
		if(f==0)cout<<0;
		cout<<min(a[1].x,a[2].x);
		return 0;
	}
	for(int i=1;i<=n/2;i++) {
		if(a[i].c!=a[n-i+1].c){
			ans=ans+min(a[i].x,a[n-i+1].x);
			k=0;
		}
		if(a[i].c==a[n-i+1].c){
			ans+=max(a[i].x,a[n-i+1].x);
			k=abs(a[i].x-a[n-i+1].x);
		}
	}
	cout<<ans;
	return 0;
}
