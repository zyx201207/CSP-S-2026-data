#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long ans=INT_MIN;
long long n,m;
int cho(long long s,long long l,long long w){
	if(w>=m){
		ans=max(ans,s);
		return 0;
	}
	for(int i=l+1;i<=n-m+1+w;i++){
		int p=(s&a[i]);
		cho(p,i,w+1);
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int kk=0;
	a[0]=-1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		cho(a[i],i,1);
	}
	cout<<ans;
	return 0;
}
