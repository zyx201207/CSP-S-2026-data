#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i1=1;i1<=n;i1++){
			int cun=0;
			if(a[i]<a[i1]){
				cun=a[i];
				a[i]=a[i1];
				a[i1]=cun;
				
			}
		}
	}
	for(int i=n;i>1;i--){
		int sum=0;
		for(int j=i-1;j>0;j--){
			int t=a[i]-a[j];
			sum=sum+t;
		}
		if(sum<=m){
			cout<<i;
			return 0;
		}
	}
}
