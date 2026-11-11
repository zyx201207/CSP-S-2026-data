#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long sum,n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]&1);
		}
		cout<<ma;
	}
	if(m==2){
		int ma=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
	}
	return 0;
}
