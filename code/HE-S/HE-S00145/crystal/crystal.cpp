#include<bits/stdc++.h>
using namespace std; 
int main(){
	cin.sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m;
	cin>>n>>m;
	long long  a[n],f[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long  res=0;
		for(int j=1;j>=n;j--){
		f[j]+=a[i]-a[j];
		res+=f[i];	
		}
		if(res>=m and a[i]!=a[i+1]){
			cout<<res<<endl;
			break;
		}
	}
	return 0;
}
