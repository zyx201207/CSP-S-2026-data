#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
int smx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<' '<<m<<'\n';
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long mx=0;
		for(int i=0;i<n;i++){
			mx=max(a[i],mx);
		}
		cout<<mx<<'\n';
	}
	else if(m==2){
		long long mx=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					continue;
				}
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx<<'\n';
	}
	else if(m==n){
		long long ans=a[0];
		for(int i=1;i<n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans<<'\n';
	}
	else{
		long long ans=a[n-1];
		sort(a,a+n);
		for(int i=1;i<m;i++){
			ans=(ans&a[n-i-1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//40pt
