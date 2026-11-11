#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
bool cmp(int a,int b){
	return a>b;
}
long long maxn=0;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=n-maxn;++i){
		long long ci=1;
		long long xm=m;
		for(int j=i+1;j<=n&&xm>=arr[j];++j){
			xm-=arr[i]-arr[j];
			ci++;
		}
		maxn=max(maxn,ci);
	}
	cout<<maxn;
}
