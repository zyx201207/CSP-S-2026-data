#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=2;i--){
		long long cnt=m;
		for(int j=i;j>=1;j--){
			b[j]=a[i]-a[j];
		}
		for(int j=i;j>=1;j--){
			if(cnt-b[j]>=0){
				ans[i]++;
				cnt-=b[j];
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(ans[i]>maxn){
			maxn=ans[i];
		}
	}
	cout<<maxn<<endl;
	return 0;
} 
