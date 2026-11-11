#include<bits/stdc++.h>
using namespace std;
long long i,v,n,a[100010],m[100010],j[100010],l,s[100010],k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int o=1;
	for(i=0;i<=n-1;i++){
		cin>>m[i]>>j[i];
		
	}
	for(i=0;i<=n-1;i++){
		for(l=1;l<=m[i];l++){
			s[o]==j[i];
			o++;
		}
	}
	for(i=1;i<=o;i++){
		if(s[i]==s[n-i-1]){
			k++;
		}
	}
	cout<<k;
	return 0;
}
