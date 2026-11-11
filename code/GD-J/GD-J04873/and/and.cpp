#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				int ans=(a[i]&a[j]&a[z]);
				if(ans>maxx)maxx=ans;
			}
		}
	}
	cout<<maxx;
}
