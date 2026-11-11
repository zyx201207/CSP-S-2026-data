#include<bits/stdc++.h>
using namespace std;
#define intl long long
intl n,m;
intl a[10001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	intl maxx=-1e9;
	for(int i=1;i<=n;i++){
		intl d=a[i];
		for(int j=i+1;j<=n;j++){
			intl s=j;
			for(int l=1;l<m;l++){
				if(s==i) s++;
				if(s>=n) s=1;
				d&=a[s++];
			}
		}
		maxx=max(maxx,d);
	}
	cout<<maxx;
	return 0;
} 

