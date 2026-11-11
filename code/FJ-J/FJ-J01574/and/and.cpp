#include<bits/stdc++.h>
using namespace std;
long long a[10001],f[10001],vis[10001];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	long long n,m,maxx=-1;
	cin>>n>>m;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[0]=max(f[0],a[i]);
	}
	if(m==1){
		cout<<f[1];
		return 0;
	} 
	if(m==n){
		int jk=a[1];
		for(int i=1;i<=n;i++)
			jk=jk&a[i];
		cout<<jk;
		return 0;
	}
//	f[1]=f[0];

	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(j-1>=0){
				//if(f[i]==-1)f[i]=max(f[i],a[i]);
				//else
				f[j]=max(f[j],f[j-1]&a[i]);
//				cout<<f[j]<<" ";
			}
//	for(int i=m;i>=1;i--)
//	if(f[i]!=0){
//		cout<<f[i];
//		return 0;
//	}
//cout<<'\n';
	cout<<f[m];
	return 0;
}

