#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500005];
int l;
int r;
int b[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		l=0;
		r=0;
		for(int j=i;j<=n;j++){
			r++;
			b[r]=a[j];
			for(int k=l+1;k<r;k++){
				if(b[k]==a[j])l=j;
			}
		}
		bool f[500005];
		for(int j=1;j<=r;j++){
			f[i]=0;
		}
		for(int j=l+1;j<=r;j++){
			if(f[a[j]]==0)ans[j]++;
			f[a[j]]=1;
		}
		for(int j=1;j<=r;j++){
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
