#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans1,ans;
int a[200005];
void dsb(int i,int s,int j){
	if(j==m)
		ans=max(ans,s);
	if(i>n)
		return ;
	dsb(i+1,s&a[i],j+1);
	dsb(i+1,s,j);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1)
			ans1&=a[i];
		else ans1=a[i];
	}
	if(n==m){
		cout<<ans1;
		return 0;
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(a[i]!=a[j])
					maxn=max(maxn,a[i]&a[j]);
		}
		cout<<maxn;
		return 0;
	}
	//3
	if(m==3){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
					if(a[i]!=a[j]&&a[i]!=a[k]&&a[k]!=a[j]){
						maxn=max(maxn,a[i]&a[j]&a[k]);
					}
						
			}
		}
		cout<<maxn;
		return 0;
	}
	//4
	if(m==4){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						if(a[i]!=a[j]&&a[i]!=a[k]&&a[k]!=a[j]&&a[i]!=a[l]&&a[l]!=a[k]&&a[l]!=a[j]){
							maxn=max(maxn,a[i]&a[j]&a[k]&a[l]);
						}
						
			}
		}
		cout<<maxn;
		return 0;
	}
	dsb(1,-1,0);
	cout<<ans;
	return 0;
}

