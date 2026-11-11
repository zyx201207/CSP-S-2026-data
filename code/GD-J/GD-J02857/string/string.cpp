#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10000001],j,ans,n;
char c[10000001];
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	j=n;
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[j]&&a[i]!=0&&a[j]!=0){
			if(a[i]==a[j]){
				ans+=a[i];
				j--;
				continue;
			}
			while(a[i]>a[j]){
				ans+=a[i]-a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			if(a[j]>a[i]){
				ans+=a[j]-a[i];
				a[i]=0;
				a[j]-=a[i];
			}
		}
	}
	cout<<ans;
} 
