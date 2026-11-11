#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long l=0,a[n+7];
	char c[999999],s[99999999];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];        
		l=l+a[i];
	}
	for(int x=1;x<=l;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++) {
				s[x]=c[j];
			}
		}
	}
	long long zf=0,m=l/2;
	for(int i=1;i<=m;i++){
		long long k=l+1-i;
		if(s[i]!=s[k]){
			zf++;
		} 
	}
	cout<<zf;
	return 0;
} 
