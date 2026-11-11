#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[5005],b[5005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int ie=0;ie<=m;ie++) b[ie]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
			}else{
				for(int k=0;k<=m;k++) b[k]=0;
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			c[j]+=b[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}