#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N],M[N],b[N];
struct asd{
	int z,w;
};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) b[j]=a[j];
		asd f[n+5]={0};
		for(int j=i;j<=n;j++){
			if(f[b[j]].z==0){
				f[b[j]].z=1;
				f[b[j]].w=j;
			}
			else{
				for(int k=f[b[j]].w;k<=j-1;k++){
					f[b[k]].z=0;
					b[k]=0;
				}
				f[b[j]].w=j;
				f[b[j]].z=1;
			}
		}
		for(int j=i;j<=n;j++){
			M[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<M[i]<<" ";
	return 0;
}


