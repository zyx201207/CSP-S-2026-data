#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,n,d,a[N],l[N],r[N];
void solve(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i--){
		for(int j=2;j<=n;j--)
			if(a[i]-a[j]<=d&&a[j]-a[i-1]>d) r[i]++;
	}
	for(int i=1;i<=n;i++){
		cout<<l[i]<<" "<<r[i];
		int j=i+1;
		for(j;j<=n;j++){
			if(a[j]-a[i]<d) break;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<l[i]<<" "<<r[i];
		int j=i+1;
		for(j;j<=n;j++){
			if(a[j]-a[i]<d) break;
		}
	}

}
int main(){  
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	solve();
	return 0;
}
