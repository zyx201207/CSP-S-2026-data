#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500500],last[300500],z[300500];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j!=last[a[j]]) j=last[a[j]];
			z[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<' ';
	}
	return 0;
} 
