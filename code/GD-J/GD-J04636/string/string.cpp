#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	long long a[n];
	string hui;
	for(int i=0;i<n;i++){
		cin>>a[i]>>hui[i];
	}
	long long ans=0;
	int x=0;
	int y=n-1;
	while(x<y){
		//cout<<a[x]<<" "<<a[y]<<" "<<ans<<endl;
		if(hui[x]!=hui[y]){
			ans=ans+min(a[x],a[y]);
		}
		if(a[x]>=a[y]){
			a[x]=a[x]-a[y];
			a[y]=0;
		}
		if(a[y]>a[x]){
			a[y]=a[y]-a[x];
			a[x]=0;
		}
		if(a[x]==0) x++;
		if(a[y]==0) y--;
	}
	cout<<ans;
	return 0;
}
