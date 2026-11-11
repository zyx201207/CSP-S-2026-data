#include<bits/stdc++.h>
using namespace std;
int andd(int x,int y){
	string b,c;
	while(x){
		b+=x%2;
		x/=2;
	}
	for(int i=0;i<b.size()/2;i++){
		char f=b[b.size()-i-1];
		b[b.size()-i-1]=b[i];
		b[i]=f;
	}
	while(y){
		c+=y%2;
		y/=2;
	}
	for(int i=0;i<c.size()/2;i++){
		char f=c[c.size()-i-1];
		c[c.size()-i-1]=c[i];
		c[i]=f;
	}
	int ans=0;
	for(int i=0;i<min(b.size(),c.size());i++){
		ans*=2;
		if(b[i]&&c[i]) ans++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n-1;i>n-m;i--) ans=andd(ans,a[i]);
	cout<<ans;
	return 0;
}
