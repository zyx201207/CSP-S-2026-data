#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],maxn,b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(m==2){
		for(int i=N;i>=1;i--){
			if(b[i]>=2){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)maxn=max(a[i]&a[j],maxn);
		}
	}
	cout<<maxn;
	return 0;
}
