#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long a[500005],b[500005],f[500005],m,max1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[i]+=(a[i]-a[j]);
		}
	}
	int ans,f;
	f=0;
	for(int i=2;i<=n;i++){
		if(b[i]>m){
			ans=i-1;
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<n;
	}
	else{
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
