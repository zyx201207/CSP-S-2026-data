#include<bits/stdc++.h>
using namespace std;
long long n,m,a[9999999],t[9999999],p[9999999],w[9999999],tb=1,s[9999999],j;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=j;i<=n;i++){
		j++;
		s[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

