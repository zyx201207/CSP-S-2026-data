#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long maxn,maxm=0,b;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b=b&a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	} 
	if(m==n){
		cout<<b;
		return 0;
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxm=max(maxm,a[i]&a[j]);
			}
		}
	}
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	cout<<maxm;
	return 0;
}
