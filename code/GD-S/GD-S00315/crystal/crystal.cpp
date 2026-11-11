#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans=0,cz=0;
int mx=-1,ix=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	bool flag1=true,flag2=true;
	int k,r=(n+1)/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]>=mx&&abs(r-i)<abs(r-ix)){
			mx=b[a[i]];
			ix=i;
		}
		if(i>1){
			if(i==2) k=a[i]-a[i-1];
			else if((a[i]-a[i-1])!=k) flag1=false;
		}
		if(i>1&&a[i]!=a[i-1]){
			flag2=false;
		}
	}
	if(flag2==true){
		cout<<n;
		return 0;
	}
	else if(flag1==true)
	{
		int y=1;
		ans++;
		for(int i=1;i<=r+1;i++){
			if((r+y)<=n&&(cz+(k*y)<=m)){
				ans++;
				cz+=k*y;
			}
			if((r-y)>=1&&(cz+(k*y)<=m)){
				ans++;
				cz+=k*y;
			}
			y++;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		sort(a+1,a+n+1);
		if(b[a[r]]<b[a[ix]]) r=ix;
		ans+=b[a[r]];
		int y=1,p=b[a[r]];
		for(int i=1;i<=(n+1)/2;i++){
			int k1=abs(p-a[y+r]),k2=abs(p-a[r-y]);
			if((r+y)<=n&&(cz+(k1*y)<=m)){
				ans++;
				cz+=k1*y;
			}
			if((r-y)>=1&&(cz+(k2*y)<=m)){
				ans++;
				cz+=k2*y;
			}
			y++;
		}
		cout<<ans;
		return 0;
	}
	return 0;	
} 
