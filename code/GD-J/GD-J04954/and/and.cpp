#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int h=1;h<=m;h++){
			for(int j=1;j<=n;j++){
				b[i]=(a[i]&a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		s=max(s,b[i]);
	}
	cout<<s;
	return 0;
} 
