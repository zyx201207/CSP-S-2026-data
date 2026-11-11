#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+6;
ll n,m,a[N],ans,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j)ans=max(ans,(a[i]&a[j]));
		cout<<ans;		
		return 0;		
	}
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int j=0;j<n;j++){
			k=(1<<30)-1;
			for(int i=0;i<n;i++)
				if(i!=j)
					k&=a[i];
			ans=max(ans,k);
		}
		cout<<ans;
		return 0;
	}
	k=a[n-1];
	for(int i=n-1;i>=n-m;i--){
		k&=a[i];
	}
	cout<<k;
	return 0;
} 
