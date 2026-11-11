#include<bits/stdc++.h>
using namespace std;
char a[500000];
int n,m;
char b;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>b;
		for(int j=1;j<=m;j++){
			a[j+l]=b;
		}
		l+=m;
	}
	for(int i=1;i<=l/2;i++){
		if(a[l-i+1]!=a[i]) ans++;
	}
	cout<<ans;
}
