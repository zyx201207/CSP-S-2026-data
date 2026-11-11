#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[5001],f[5001][5001],c,d,l,o,p;
bool k=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	l=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=l){
			k=1;
			break;
		}
	}
	if(k==1){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				f[i][j]=a[j]-a[i];
			}
		}
		for(int j=1;j<n;j++){
			for(int i=j-1;i>=0;i--){
				b[j]+=f[i][j];
				if(b[j]<=m) c++;
			}
			d=max(c,d);
			c=0;
		}
		cout<<d+1;
	}
	else{
		for(int i=1;i<=n-1;i++){
			o+=l*i;
			if(o>m) p=i;
		}
		cout<<p;
	}
	return 0;
} 
