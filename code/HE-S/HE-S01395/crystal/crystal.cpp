#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<m;i++){
		if(a[ans]==a[ans+1]){
			ans++;
			continue;
		}else{
			a[ans]++;
		}
	}
	cout<<ans+1;
	return 0;
}
