#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    for(int i=1;i<=n-m+1;i++){
    	long long ans=a[i];
    	for(int j=a[i]+1;j<=a[i]+m-1;j++){
    		ans&=a[j];
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
}
