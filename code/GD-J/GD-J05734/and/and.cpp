#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[2005];
	for(it i=1;i<=n;i++){
		cin>>a[i];
	}
	int o=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=a[i]&a[j];
			if(o<k){
				o=k;
			}
		}
	}
	cout<<o;
	return 0;
} 
