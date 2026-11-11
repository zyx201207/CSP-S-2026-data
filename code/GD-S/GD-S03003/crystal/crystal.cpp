#include<bits/stdc++.h> 
using namespace std;
int nm[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ont","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nm[i];
	}
	long long npp=0;
	for(int i=1;i<n;i++){
		npp+=nm[i];
	}
	if(npp<=m){
		cout<<n;
		return 0;
	}
	int z,u=m;
	sort(nm+1,nm+n+1);
	z=nm[(n+1)/2];
	for(int i=1;i<=n;i++){
		while(nm[i]<z&&u>0){
			nm[i]=nm[i]+1;
			u--;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(nm[i]==z){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
