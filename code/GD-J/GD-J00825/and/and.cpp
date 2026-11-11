#include<bits/stdc++.h>
using namespace std;
const int B=31;
const int N=2e5+5;
int n,k;
int a[N];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cur=0;
	for(int b=B-1;~b;b--){
		int cnt=0,nw=cur|(1<<b);
		for(int i=1;i<=n;i++){
			cnt+=((a[i]&nw)==nw);
		}
		if(cnt>=k){
			cur=nw;
		}
	}
	cout<<cur<<"\n";
	return 0;
}

