#include<bits/stdc++.h>
using namespace std;
int a[10000086]={};
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==1){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=a[i];
			for(int k=1;k<=m;k++){
				sum&=a[j+k];
			}
			maxn=max(maxn,sum);
		}
	}
	cout<<maxn;
	return 0;
}
