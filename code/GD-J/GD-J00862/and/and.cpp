#include<bits/stdc++.h>
using namespace std;
int a[301000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans,bj;
	for(int i=n;i>=n-m+1;i--){
		bool k=false;
		long long u=1;
		for(int j=1;j<=29;j++){
			if(u==a[i]) k=true;
			u*=2;
		}
		if(!k){
			ans=a[i];
			bj=i;
			goto here;
		}
	}
	here:
	for(int i=bj-1;i>=bj-m+1;i--){
		ans=ans&a[i];
	} 
	
	cout<<ans;
	return 0;
} 
