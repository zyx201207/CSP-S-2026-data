#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],maxn,maxx,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n;++j){
			if(a[j]<=i){
				cnt+=i-a[j];
			}
			if(a[j]<i){
				a[j]=i;
			}
			if(cnt>=m){
				break;
			}
		}
		if(cnt>=m){
			break;
		}
	}
	for(int i=1;i<=n;++i){
		b[a[i]]++;
	}
	for(int i=1;i<=maxn;++i){
		maxx=max(b[i],maxx);
	}
	cout<<maxx;
} 
