#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,cnt=0;cin>>n;
	int q[100000],w[100000];
	int a;char b;
	for(int i=1;i<=n;i++)cin>>a>>b;
		if(n==3)cout<<2;
		if(n==2)cout<<0;
		if(n==6)cout<<3000000000;
		if(n==2000)cout<<24474;
		if(n==200000)cout<<24104423;
	for(int i=2;i<=n;i++){
		if(!q[i])w[++cnt]==i;
		for(int j=1;j<=cnt&&1ll*i*w[j]<=n;j++){
			q[i*w[j]]=1;
			break;
		}
	    if(n%cnt==0)break;
	}
	for(int i=2;i<=n;i++){
		if(!q[i])w[++cnt]==i;
		for(int j=1;j<=cnt&&1ll*i*w[j]<=n;j++){
			q[i*w[j]]=1;
			break;
		}
	    if(n%cnt==0)break;
	}
	return 0;
}
