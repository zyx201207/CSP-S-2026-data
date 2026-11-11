#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
long long b[300010];
long long a1[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		a1[i]=1;
	}
	for(int i=1;i<=n;i++){
		long long x=a1[i]+a1[i-1];
		a1[i]=0;
		a1[b[a[i]]]+=x;
	}
	for(int i=1;i<=m;i++){
		cout<<a1[b[i]]<<" ";
	}
}
