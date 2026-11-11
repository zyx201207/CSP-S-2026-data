#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	int f=0;
	for(int i=3;i<=n;i++) if(d[i]!=d[i-1]) f=1;
	if(f==0){
		int k=0;
		for(int i=1;i<=n;i++){
			k+=(i-1);
			if(d[i]*k>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	int maxx1=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=j-i+1,x=j;
			long long sum=0;
			while(k>0){
				sum+=d[x]*(k-1);
				x--;
				k--;
			}
			if(sum<=m) maxx1=max(maxx1,j-i+1);
		}
	}
	cout<<maxx1;
	return 0;
}
