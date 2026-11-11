#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c=0,a1=1,a2=1;
	cin>>n>>m;
	int a[n+3],b[n+3]={0},k=10000000,l;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i]+=max(a[i]-a[j],a[j]-a[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(k>b[i]){
			k=b[i];
			l=i;
		}
	}
	while(m>0){
		int b;
		if(a[l+a1]-a[l]>a[l]-a[l-a2]&&m>=a[l]-a[l-a2]){
			m-=(a[l]-a[l-a2]);
			c++;
			a2++;
		}
		else if(a[l+a1]-a[l]<=a[l]-a[l-a2]&&m>=a[l+a1]-a[l]){
			m-=(a[l+a1]-a[l]);
			c++;
			a1++;
		}
	}
	cout<<c;
} 
