#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",strout);
	int n,m;
	int a[1005],ans=0;
	scanf("%d,",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n+1);
	int j=n/2+1;
	for(int i=1;i<=n;i++){
		if(a[i]>a[j]){
			break;
		}
		while(a[i]<a[j]&&m){
			m--;
			a[i]++;
		}
		if(a[i]==a[j]){
			ans++;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]<=a[j]){
			m=m-(a[i]-a[j]);
		}
		if(m>=0){
			ans++;
		}
	}
	
	
	cout<<ans/2;
	return 0;	
	
	
	
	
} 
