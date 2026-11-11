#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[1005];
	int c[1005];
	int b[1005];
	int s=0;
	for(int i=2;i<=n+2;i++){
		cin>>a[i]>>c[i];
	}
    a[0]=0;
	a[1]=0;
	for(int j=2;j<=n+2;j++){
		int x=a[j]+a[j-1];
		int z=a[j-2]+a[j-1];
		for(int y=z;y<x;y++){
			b[y]=c[j];
			cout<<c[j];
		}
		s=max(s,x); 
	}
	int cnt=0;
	while(s--){
		for(int u=2;u<=s;u++){
			if(b[u]!=b[s]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
