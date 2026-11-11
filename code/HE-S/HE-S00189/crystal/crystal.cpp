#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,mi,j;
long long q[N],p[N];
long long a[N];
long long mn=1e12+1,mx=-1;
long long ans[N];
bool s=1;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)continue;
		if(i==2){
			j=a[i]-a[i-1];
			continue;
		}
		if(!(a[i]-a[i-1]==j))s=0;
	}
	if(s&&m!=0){
		long long t,ii;
		for(int i=2;i<=n-1;i+=j){
			t+=i;
			ii=i;
			if(m<=t){
				cout<<i;
				return 0;
			}
		}
		cout<<ii;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
			q[i]=(a[i+1]-a[i])*i;
		int cnt=0;
		for(int l=1;l<n;l++){
			for(int r=1;r<=n;r++){
				long long sum=0;
				for(int i=l;i<r;i++){
					sum+=q[i];
				}
				if(sum<=m){
					ans[++cnt]=r-l+1;
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			mx=max(ans[i],mx);
		}
		cout<<mx;
	}
	return 0;
} 
