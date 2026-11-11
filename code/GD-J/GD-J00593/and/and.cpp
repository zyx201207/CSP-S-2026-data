#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int a[2001];
int awyu(int a,int b){
	int c=a&b;
	return c; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[j-1]) continue;
				maxx=max(maxx,awyu(a[i],a[j]));
			}
		}
		cout<<maxx;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=awyu(a[i],ans);
		}
		cout<<ans;
	}
	return 0;
}
