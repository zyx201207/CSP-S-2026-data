#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,maxn=0,ml=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		ml=m;
		ans=0;
		for(int j=i-1;j>=1;j--){
			if(ml>=a[i]-a[j]){
				ans++;
				ml-=a[i]-a[j];
			}else{
				break;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn+1;
	return 0;
} 
