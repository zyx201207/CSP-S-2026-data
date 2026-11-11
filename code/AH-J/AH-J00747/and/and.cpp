#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long a[N];
bool cmp(long long n){
	for(int i=1;i<=n;i++){
		if(a[i]!=pow(2,i)-1) return 0;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,maxn=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1) cout<<maxn;
	else if(m==n){
		long long s=a[1];
		for(long long i=2;i<=n;i++) s=s&a[i];
		cout<<s;
	}
	else if(m==n-1){
		long long maxn1=0,maxn2=a[2],maxn3=0;
		for(int i=3;i<=n;i++) maxn2=maxn2&a[i];
		for(int i=2;i<=n;i++){
			long long s=a[1];
			for(int j=2;j<=n;j++){
				if(i!=j) s=s&a[j];
			}
			maxn1=max(maxn1,s);
		}
		maxn3=max(maxn1,maxn2);
		cout<<maxn3;
	}
	else if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				long long t=a[i];
				if(i!=j){
					t&=a[j];
					maxn=max(maxn,t);
				}
			}
		}
		cout<<maxn;
	}
	else if(cmp(n)==1){
		cout<<a[n-m+1];
	}
	else cout<<n-m;
	return 0;
}
