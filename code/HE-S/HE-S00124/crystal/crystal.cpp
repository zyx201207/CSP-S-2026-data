#include<bits/stdc++.h>
using namespace std;
long long n,m,total=1,ans;
const int N=5e5+10;
int a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	bool flag=true;
	for(int i=2;i<=n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			flag=false;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(pre[i]-i<=m){
				total=i;
			}
		} 
		cout<<total;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		ans=1;
		long long m1=m;
		for(long long j=i-1;j>=1;j--){
			if(a[i]-a[j]>m1){
				break;
			}else{
				m1-=(a[i]-a[j]);
				ans++;
			}
			if(m1<=0){
				break;
			}
		}
		total=max(ans,total);
	}
	cout<<total;
	return 0;
} 
