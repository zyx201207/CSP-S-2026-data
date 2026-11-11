#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
long long x[N];
long long a[N];
long long w[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	x[1]=1;
	for(int i=2;i<=n;i++){
		x[i]=1;
		if(a[i]==a[i-1]) x[i]=x[i-1]+1;
	}
	w[0]=0;
	long long ans=0;
	for(long long i=1;i<=n;i++){
		w[i]=w[i-1]+(a[i]-a[i-1])*(i-1);
		if(w[i]<=m){
			ans=i;
		}	 
		if(w[i]>m){
			
			long long  v=w[x[i]-1]+(a[i]-a[x[i]-1])*(x[i]-1);
			if(w[i]-v<=m){
				ans=i-2v-m-w[i];
			}
		} 
	}
	cout<<ans;
	return 0;
}
