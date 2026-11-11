#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long m;int n;int mx=0;
	cin>>n>>m;
	long long a[n+5],v[n+5][n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
		long long p=m;int cnt=1;
		for(int j=0;j<i;j++){
			v[i][j]=a[i]-a[j];
			if(p>=v[i][j]){
				p-=v[i][j];
				cnt++;
			}
		}
		mx=max(mx,cnt);
	}
	cout<<mx<<'\n';
	
	return 0;
}
