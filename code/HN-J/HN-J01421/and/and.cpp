#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e5+100,M=1e7+100;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[N],n,m,maxn=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=0,j=n;
	while(i<=j){
		i++;
		bool f[N];
		int gs=m,x;
		for(int k=1;;k++){
			if(gs==0) break;
			if(f[i]!=0 || f[j]!=0) break;
			if(gs/2==0){
				x=x&a[i];
				gs-=1;
			}
			x=a[j]&a[i];
			gs-=2;
			f[i]+=1,f[j]+=1;
		}	
		maxn=max(x,maxn);
		if(i==n) j--,i=0;
	}
	cout<<maxn;
	return 0;
} 
