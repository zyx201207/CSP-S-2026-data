#include<bits/stdc++.h>
using namespace std;
long long n,m,len,a[500005],f[500005],ans[300005];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=len;k++){
				if(f[k]==a[j]){
					for(int k1=k;k1<=len;k1++){
						f[k1]=0;
					}
					len=k-1;
				}
			}
			f[++len]=a[j];
		}
		for(int j=1;j<=len;j++){
			ans[f[j]]++;
		}
		memset(f,0,sizeof(f));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

