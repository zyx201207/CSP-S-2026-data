#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		int cn,ans;
		cin>>cn;
		ans=cn;
		for(int i=2;i<=n;i++){
			cin>>cn;
			ans=ans&cn;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int kp,ma;
		for(int i=1;i<=n;i++){
			cin>>kp;
			ma=max(ma,kp);
		}
		cout<<ma;
		return 0;
	}
	if(m==2){
		int ma=-1;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int ka;
			for(int j=i;j<=n;j++)ka=a[i]&a[j];
			ma=max(ma,ka);
		}
		cout<<ma;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		int pp=a[2];
		for(int i=n;i>=3;i--)pp=pp&a[i];
		cout<<pp;
		return 0;
	}
	int p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cout<<0;
			return 0;
		}
	}cout<<1;
	return 0;
}
