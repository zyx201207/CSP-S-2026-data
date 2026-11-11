#include<bits/stdc++.h>
#define N 2010
#define INF 1e18
#define int long long
using namespace std;
int n,m,f=1,ma,a[200010];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(f==1){
			int t=a[i]+1;
			while(t%2==0){
				t/=2;
			}
			if(t!=1)
			f=0;
		}
	}
	if(f==1){
		int ans=2147483637;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	int t=1<<n;
	for(int i=1;i<t;i++){
		int s1=0,s2=2147483647;
		for(int j=1;j<=n;j++){
			int t1=1<<(j-1);
			if(i&t1){
				s1++;
				s2=s2&a[j];
			}
		}
		if(s1==m)
		ma=max(ma,s2);
	}
	cout<<ma;
	return 0;
}
