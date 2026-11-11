#include<bits/stdc++.h>
using namespace std;
int n,m;int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		
	}
for(int i=0;i<n;i++){
		for(;a[i]!=a[i+2];){if(m=0)break;
			a[i]=a[i]+1;m--;
		}
		for(;a[i+1]!=a[i+2];){
			a[i+1]=a[i+1]+1;m--;if(m=0)break;
		}
		
	}
	for(int i=0;i<n;i++){
		if(a[i]=a[i+1])
		ans++;
	}
	cout<<ans;
	return 0;
}
