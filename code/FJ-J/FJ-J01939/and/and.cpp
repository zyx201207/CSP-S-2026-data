#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-2e9;
	for(int i=1;i<=n-m+1;i++){
		for(int j=i+1;j<=n;j++){
			int c=a[j];
			for(int k=1;k<=m;k++){
				int b=i;
				c&=a[b++];
			}
			if(c>maxx){
				maxx=c;
			}
		}
	}
	cout<<maxx;
	return 0;
} 
