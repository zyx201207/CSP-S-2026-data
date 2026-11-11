#include<bits/stdc++.h>
using namespace std;
int n,m,x=0,ans=0,ans2=0,t=0;
int a[100001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t+=a[i];
	}
	for(int i=1;i<=n;i++){
		x=max(a[i],a[i+1]);
	}
	for(int i=1;i<=n;i++){
		ans2=x*(n-1);
		if(ans2-t+x<=m){
			ans=n;
			break;
		}else{
			n--;
		}
	}
	cout<<ans;
	return 0;
}
