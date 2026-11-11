#include<bits/stdc++.h>
using namespace std;
long long n,m,mna=100000000000;
long long a[500007],s[500007],b[500007],c[500007],d[500007];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int p=1;p<=n;p++){
		for(int q=1;q<=n;q++){
			if(a[q]<=mna){
				mna=a[q];
			}
		}
		for(int o=1;o<=n;o++){
			if(a[o]==mna){
				b[p]=a[o];
				a[o]=1000000000002;
				mna=1000000000001;
				break;
			}
		}
	}
	for(int r=n;r>=1;r--){
		for(int t=r;t>=1;t--){
			c[r]=b[r];
			c[r]-=b[t];
			d[r]+=c[r];
		}
	}
	for(int x=1;x<=n;x++){
		if(d[x]>m){
			cout<<x-1;
			break;
		}
	}
	return 0;
} 
