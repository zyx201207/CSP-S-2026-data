#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5000005],b[5000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;	
	int o=0;		
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	o=a[2]-a[1];
	int u=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=o) u=1;
	}

	if(u==0){
		int k=a[2]-a[1];
		int p=0,kk=0;
		for(int i=0;i<=m;i+=kk){
			p++;
			kk+=k;
		}
		cout<<p;			
	}

	else{
		int p=0;
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			int r=0,e=0;
			for(int j=i;j>=1;j--){
				r+=a[i]-a[j];
				if(r>m){
					break;
				}
				e++;
			}
			p=max(p,e);
		}
		cout<<p;
	}
	return 0;
}
