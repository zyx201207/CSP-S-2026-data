#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005]={},sum[200005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			sum[i]=a[i];
		}else{
			sum[i]=sum[i-1]&a[i];
		}
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}else if(m==n){
		cout<<sum[n];
	}else{
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maxn=max(a[i]&a[j],maxn);
			}
		}
	}    
	return 0;
}
