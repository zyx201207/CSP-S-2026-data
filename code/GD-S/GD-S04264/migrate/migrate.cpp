#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		int s=0;
	cin>>n>>d;
	int x[n+10],y[n+10]={0};
	for(int i=1;i<=n;i++)
	cin>>x[i];	
	for(int i=1;i<n;i++)
	y[i]=abs(x[i+1]-x[i]);
	for(int i=1;i<n-2;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			ans+=y[j-1];
		if(j-i>=3)
			if(ans>=d&&ans%d!=0)	
			s++;
			}
	}
	cout<<s;
	}
	return 0;
}

