#include<bits/stdc++.h>
using namespace std;
long long a[500003];
long long b[2][500003];
int main(){
	freopen("crystal.out","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	int k=0;
	b[0][0]=a[0];
	b[1][0]=1;
	for(int i=1;i<n;i++){
		if(a[i]==b[0][k]) b[1][k]++;
		else{
			k++;
			b[0][k]=a[i];
			b[1][k]++;
		}
	}
	long long ans=0;
	if(m==0){
		for(int i=0;i<n;i++) ans=max(ans,b[1][i]);
		cout<<ans;
		return 0;
	}
	for(int i=k-1;i>0;i--){
		int mb=b[0][i];
		int j=i-1;
		int yu=m;
		while(yu!=0&&j>=0){
			if(yu<mb-b[0][j]) break;
			yu=yu-mb+b[0][j];
			b[1][i]++;
			j--;
		}
	}
	for(int i=0;i<n;i++) ans=max(ans,b[1][i]);
	cout<<ans<<endl;
	//for(int i=0;i<=k;i++) cout<<b[0][i]<<" "<<b[1][i]<<endl;
	return 0;
}
