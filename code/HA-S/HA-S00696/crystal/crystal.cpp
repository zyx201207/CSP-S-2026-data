#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long b;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			b=a[i]-a[j];
			if(b>m){
				break;
			}
			a[j]+=b;
			m-=b;
		}
		if(b>m){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[1]==a[i]){
			ans++;
		}
	}
	cout<<ans;
}
