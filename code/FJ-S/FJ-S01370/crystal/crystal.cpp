#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int a[1000000000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	sort(a+1,a+i-1);
	}
	if(m%2==0){
		m/=2;
		for(int i=1;i<=m;i++){
			if(m-i>=0){
				ans++;
			}
		}
		cout<<ans*2+1;
	}else{
		m=(m+1)/2;
		for(int i=1;i<=m;i++){
			if(m-i>=0){
				ans++;
			}
		}
		cout<<ans*2+1;
	}
	return 0;
} 
