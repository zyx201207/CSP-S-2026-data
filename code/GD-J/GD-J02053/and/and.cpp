#include<bits/stdc++.h>
using namespace std;
int d[200005],c[200005];
int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	int n,m,cnt=0; 
	cin>>n>>m;
	int a[n],b[30];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[29]=1;
	for(int i=28;i>=0;i--){
		b[i]=b[i+1]*2;
	}
	for(int i=0;i<30;i++){
		int ans=0,z=0;
		for(int j=0;j<n;j++){
			if(a[j]/b[i]%2==1){
				ans++;
			}else{
				d[z]=j;
				z++;
			}
		}
		if(ans>=m){
			c[i]++;
			for(int j=0;j<z;j++){
				a[d[j]]=0;
			}
		}
	}
	for(int i=0;i<30;i++){
		cnt+=c[i]*b[i];
	}
	cout<<cnt;
	return 0;
}
