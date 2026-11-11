#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1;
long long a[500005];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%l ",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		while(m){
			a[i-1]++;
			m--;
			if(a[i]==a[i-1]){
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
