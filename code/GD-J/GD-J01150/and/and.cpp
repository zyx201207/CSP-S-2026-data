#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=0,n,m,a[200010],N;
int main(){
	freopen("and.in" ,"r",stdin );
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int k=(1<<30);k>=1;k>>=1){
		ll cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]&k)cnt++;
		}
		if(cnt>=m){
			N=n;
			n=0;
			for(int i=1;i<=N;++i){
				if(a[i]&k)a[++n]=a[i];
			}
			ans|=k;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
