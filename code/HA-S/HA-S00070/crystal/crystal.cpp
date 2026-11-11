#include <bits/stdc++.h>
using namespace std;
long long n,m,k=1,k2=2,cnt;
long long a[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	while(cnt<m){
		for(int i=1;i<=k;i++){
			a[i]++;
			cnt++;
		
		}
		while(a[k]==a[k2]){
			k++;
			k2++;
		}
	}
	
	cout<<k;
	return 0;
} 
