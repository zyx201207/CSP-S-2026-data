#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],add[500010]={0},ans=0;
bool check(long long l,long long r){
	if((r-l)*a[r]-add[r-1]+add[l-1]>m)return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		add[i]=a[i]+add[i-1];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(check(i,j)){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0; 
}
