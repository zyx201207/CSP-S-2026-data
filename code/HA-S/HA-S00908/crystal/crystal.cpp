#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,w=0,t;
int a[500005];
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			w++;
		}
	}
	if(n%2!=0){
		t=n+1;
	}
	for(int i=1;i<=t/2+w;i++){
		int b=0;
		b=a[t/2+w]-a[i];
		if(b<=m){
			a[i]+=b;
			m-=b;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	if(ans>0){
		cout<<ans+1;
	}
	else cout<<ans;
	return 0;
}
