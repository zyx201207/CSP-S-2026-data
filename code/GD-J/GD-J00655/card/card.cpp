#include<bits/stdc++.h>
using namespace std;
long long t[400000];
long long a[600000];
long long num[600000];
long long vis[400000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		num[i]=a[i];
		vis[i]=-1;
	}
	for(long long i=n-1;i>=0;i--){
		if(vis[a[i]]!=-1){
			a[i]=vis[a[i]];
			vis[a[i]]=-1;
		}
		else{
			vis[a[i]]=i;
			a[i]=-1;
		}
	}
	for(long long i=1;i<=n;i++){
		long long j=i-1;
		while(j<n){
			if(a[j]!=-1) j=a[j];
			t[num[j]]++;
			j++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
} 
