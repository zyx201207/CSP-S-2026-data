#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[500005],s[500005],maxa=-1e9;
long long m,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=i;
		s[i]+=s[i-1]+a[i];	
	}sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<i;j++)
		{if((i-1)*a[i]-(s[i]-s[j])<=m){
				maxa=max(maxa,i-j+1);
			}
		}
	}cout<<maxa;
	return 0;
} 
