#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=5e5+5;
int n;
long long m;
long long a[maxn],b[maxn];
long long ans;
long long q;
void f(int x){
	long long num=0,cnt=m;
	for(int i=1;i<=n;i++) b[i]=abs(a[i]-x);
	sort(b,b+n+1);
	for(int i=1;i<=n;i++){
		if(cnt<b[i]) break;
		cnt-=b[i];
		num++;
	}
	ans=max(ans,num);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) q=max(q,a[i]);
	if(q*n<=m){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=q;i++){
	    f(i);
		if(ans==n) break;	
	}
	cout<<ans;
	return 0;
} 
