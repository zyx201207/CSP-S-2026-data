#include<bits/stdc++.h>
using namespace std;
int f[200100];
int k[200100][40];
int a[200100];
int siz[200100];
signed main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		int s=a[i];
		int t=0;
		while(s!=0){
			k[i][t]=s%2;
			s/=2;
			t++;
		}
	}
	for(int p=30;p>=0;p--){
		int t=0;
		for(int i=1;i<=n;i++){
			if(f[i]==0&&k[i][p]==1) t++;
		}
		if(t>=m){
			for(int i=1;i<=n;i++)
			if(k[i][p]==0)f[i]=1;
		}
	}
	int ans=INT_MAX;
	for(int i=1;i<=n;i++){
		if(f[i]==0)ans=ans&a[i];
	}cout<<ans;
	return 0;
}

