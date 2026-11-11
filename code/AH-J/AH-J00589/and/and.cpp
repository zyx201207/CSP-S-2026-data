#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+20;
ll n,m;
ll maxn;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}
		maxn=a[n];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
					maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	cout<<maxn;
	return 0;
}
