#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10;
ll n,m;
ll a[N];
ll ans=0;
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		for(int j=1;j<n+1;++j){
			if(a[i]!=a[j]){
			m=m+a[i]-a[j];
			if(m>0){
				a[i]=a[j];
			}
		} 
			if(a[i]==a[j] and a[j]!=a[j+1]){
				m=m+a[j]-a[j+1];
				if(m>0){
					a[j]=a[j+1];
					a[i]=a[j+1];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[0]==a[i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}

