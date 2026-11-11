#include<bits/stdc++.h>
using namespace std;
int n,a[200005],tot,maxn,m;
int cnt1_(int n){
	int cnt=0;
	while(n){
		cnt+=n&1;
		n>>=1;
	}
	return cnt;
}
bool cmp(int a,int b){
	if(cnt1_(a)==cnt1_(b))
		return a>b;
	return cnt1_(a)>cnt1_(b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot=(i==1?a[1]:tot&a[i]);
		maxn=max(maxn,a[i]);
		
	}
	if(m==1){
		cout<<maxn;
	}
	else if(m==n){
		cout<<tot;
	}
	else if(1){
		//cout<<511;
		sort(a+1,a+n+1,cmp);
		int ans = a[1];
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
}
