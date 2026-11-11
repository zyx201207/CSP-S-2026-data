#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
	}
	if(m==3){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int z=j+1;z<=n;z++)
					ans=max(ans,a[i]&a[j]&a[z]);
	} 
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
	}
	if(m==n-1){
		int mid=1;
		while(mid<=n){
			for(int i=1;i<=n;i++)
				if(i!=mid){
					ans=a[i];
					for(int j=i+1;j<=n;j++) ans=max(ans,ans&a[j]);
				}
			mid++;
		}
	}
	cout<<ans;
	return 0; 
}
