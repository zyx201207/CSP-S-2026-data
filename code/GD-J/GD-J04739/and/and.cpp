#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[1]=max(f[1],a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==f[1]) continue;
		for(int j=m;j>=1;j--){
			if(j>i) continue;
			f[j]=max(f[j],f[j-1]&a[i]);
			//cout<<f[j]<<" "<<j<<" "<<i<<endl;
		}
	}
	//cout<<endl;
	cout<<f[m]<<endl;
	return 0;
}




