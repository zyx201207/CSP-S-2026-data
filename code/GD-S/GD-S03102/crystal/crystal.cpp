#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[510000];
long long maxx;
long long mm;
unordered_map<long long,bool>vis;
bool checkAB(){
	int res=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=res){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1,x;i<=n;i++){
		cin>>a[i];
	}
	if(checkAB()){
		long long mmm=min(m,n)/(a[2]-a[1]);
		cout<<((long long)sqrt(1+8*mmm)-1)/2+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long j=n;j>=1;j--){
		if(!vis[a[j]]){
			vis[a[j]]=1;
			long long ans=1;
			long long z=m;
			for(long long i=j-1;i>=1;i--){
				if(a[j]-a[i]<=z){
					z-=a[j]-a[i];
					ans++;
				}else{
					break;
				}
			}
			if(ans>maxx){
				maxx=ans;
				mm=j;
			}
		}
	}
	cout<<maxx;
	return 0;
}
