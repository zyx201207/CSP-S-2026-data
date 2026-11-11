#include<bits/stdc++.h>
using namespace std;
long long shuzi[200010];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	string a;
	long long n,h=0,p=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>shuzi[i]>>a[i];
		if(shuzi[i]==1000000000)h++;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	long long ans=0;
	if(h==n){
		for(int i=0;i<=n/2;i++){
			if(a[i]==a[n-i])ans+=1000000000;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			p=1;
		}
	}
	if(p==0){
		cout<<0;
	}
	return 0;
}
