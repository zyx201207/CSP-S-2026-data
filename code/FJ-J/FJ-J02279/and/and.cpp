#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-1;i>n-m;i--){
		int x=a[i],y=1;
		a[i]=0;
		while(a[i+1]||x){
			if(x%2==1&&a[i+1]%2==1) a[i]+=y;
			y*=2;
			x/=2;
			a[i+1]/=2;
		}
	}
	cout<<a[n-m];
	return 0;
}
