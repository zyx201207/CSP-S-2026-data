#include<bits/stdc++.h>
using namespace std;
long long a[500500],f[500500][500500];
long long cnt[500500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=a[j]-a[i];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			cnt[j]+=f[i][j];
		}
	}
	long long maxx=-1,id;
	for(long long i=1;i<=n;i++){
		if(m>=cnt[i]){
			maxx=max(maxx,cnt[i]);
			id=i;
		}
	}
	cout<<id;
	return 0;
} 
