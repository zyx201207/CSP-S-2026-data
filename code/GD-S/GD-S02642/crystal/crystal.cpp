#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	for(int i=n;i>=1;i--){
		int cnt=n-i+1;
		if(i*a[i]-s[i]<=m){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}

