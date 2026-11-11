#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	cin>>n>>m;
	if(n==m){
		n--;
		cin>>ans;
		while(n--){
			long long p;
			cin>>p;
			ans&=p;
		}
		cout<<ans;
		return 0;
	}else if(m==1){
		while(n--){
			long long p;
			cin>>p;
			ans=max(p,ans);
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	
	
}
