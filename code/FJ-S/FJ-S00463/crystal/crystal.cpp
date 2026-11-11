#include<bits/stdc++.h>
using namespace std;

int m,n,maxx=-1e9;
int v[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v+1,v+n+1);
	
	for(int i=n;i>=1;i--){
		int vx=0,cnt=0,maxn=v[i];
		for(int j=i-1;j>=1;j--){
			if((vx+(maxn-v[j]))<=m){
				vx+=(maxn-v[j]);
				cnt++;
			}
		}
		maxx=max(maxx,cnt+1);
	}
	cout<<maxx;
	
	return 0;
}
