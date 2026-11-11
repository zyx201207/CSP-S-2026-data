#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],pr[N];
int ans=0;
bool pai(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,pai);
	for(int i=1;i<=n;i++){
		pr[i]=pr[i-1]+(a[1]-a[i]);
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			long long p=pr[mid]-pr[i-1]-(a[1]-a[i])*(mid-i+1);
			if(p<=m){
				l=mid;
			}
			else r=mid-1;
		}
		ans=max(ans,(l-i+1));
	}
	cout<<ans;
	return 0;
}
