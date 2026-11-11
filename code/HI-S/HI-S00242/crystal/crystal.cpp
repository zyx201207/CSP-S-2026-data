#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int n,a[500000],sum=0,ans=0,num=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			sum=0;
			num=1;
			for(int k=j;k<=i-1;k++){
				sum+=a[i]-a[k];
				num++;
			}
			if(sum<=m){
				ans=max(ans,num);
			} 
		}
	}
	cout<<ans;
	
	
}

