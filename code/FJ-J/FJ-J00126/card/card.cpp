#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
int main(){
	freopen("kard.in","r",stdin);
	freopen("kard.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[a[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
