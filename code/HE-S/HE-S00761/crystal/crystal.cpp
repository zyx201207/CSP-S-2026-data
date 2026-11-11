#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int t=1;
	while(m>0){
		m=m-(a[t+1]-a[t]);
		a[t]=a[t+1];
		for(int j=1;j<t;j++){
			m=m-(a[j+1]-a[j]);
			a[j]=a[j+1];
		}
		t++;
	}
	int ans=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
