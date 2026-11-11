#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,d;
int sum;
ll ans;
ll a[2000010],b[200010];
void solve(){
	cin>>n>>d;
	sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]+d<a[j]){
				b[i]=j-1-i;
				break;
			} 
		}
	}
	for(int i=1;i<=n;i++){
		ans=1;
		for(int j=i;j<=n;j++){
			ans*=b[j];
			if(ans==2){
				sum++;
			}
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
