#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mn=2e5;
const int maxn=mn+10;
int n,m,a[maxn];
bool cmp(int a,int b){
	return a>b;
}signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;return 0;
	}if(m==1){
		int maxa=0;
		for(int i=1;i<=n;i++)maxa=max(maxa,a[i]);
		cout<<maxa;return 0;
	}else if(m==2){
		int maxa=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					maxa=max(maxa,a[i]&a[j]);
		cout<<maxa;return 0;
	}sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
