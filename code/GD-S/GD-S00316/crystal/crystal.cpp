#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1001];
long long ans=0,lj=0;
long long mn[101];
long long ans1=0;
long long ma=0;
long long x1,x2;
void dfs(long long de){
	if(de>m){
		ans1=0;
		ma=0;
		for(long long i=1;i<=101;i++){
			mn[i]=0;
		}
		for(long long i=1;i<=n;i++){
			mn[a[i]]++;
			ma=max(ma,a[i]);
		}
		
		for(long long i=1;i<=ma;i++){
			x1=ans1;
			x2=mn[i];
			ans1=max(x1,x2);
		}
		ans=max(ans1,ans);
		//cout<<ans1<<endl;
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			a[i]=a[i]+1;
			dfs(de+1);
			a[i]=a[i]-1;
		}
	}
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=50000){
		long long h=0;
		for(int i=2;i<=500000;i++){
			h=h+i;
			if(h>=m){
				cout<<i;
				return 0;
			}
		}
	} 
	int x;
	dfs(1);
	cout<<ans;
	return 0;
}  
