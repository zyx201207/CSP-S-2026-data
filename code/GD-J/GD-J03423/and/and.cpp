#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0,x=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=29;i>=0;i--){
		int s=0,t=pow(2,i);
		for(int j=1;j<=n;j++){
			if(x!=0&&!(a[j]&x))continue;
			if(a[j]&t)s++;
		}
		if(s>=m){
			ans+=t;
			x=t;
		}
	}
	cout<<ans;
	return 0;
}
