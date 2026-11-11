#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,ans=0;
long long a[100005];
bool vis[100005];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
	freopen("crystal""in""r""stdin");
	freopen("crystal""out""w""stdout");
	cin>>n,m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		}
		sum/=n;
		for(int i=0;i<n;i++){
			if(sum<a[i]){
				vis[i]=1;
				a[i]=0;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=0;i<n;i++){
			long long n=sum-a[i];
			if(sum){
			vis[i]=1;
			a[i]=0;
			}
		}
		for(int i=0;i<n;i++){
			if(sum-a[i]<=vis[i]==0;){
			m=m-n;
			ans++;		
		}
	return 0;
}
