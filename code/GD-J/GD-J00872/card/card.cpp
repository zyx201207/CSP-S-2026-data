#include<bits/stdc++.h>
using namespace std;
	int n,m,a[500005],f[500][500005],t[500];
int find(int k,int aaa){
	for(int i=1;i<=t[aaa];i++){
		if(f[aaa][i]==k) return i;
	}
	return -1;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=min(499,m);k++){
		t[k]=k-1;
		for(int i=1;i<k;i++) f[k][i]=a[i];
		for(int i=k;i<=n;i++){
			int aa=find(a[i],i);
			if(aa!=-1) t[k]=aa;
			f[k][++t[k]]=a[i];
		}
	}
	for(int i=1;i<=min(499,m);i++){
		int sum=0;
		for(int x=1;x<=n;i++){
			for(int y=1;y<=t[x];y++){
				if(f[x][y]==i){
					sum++;
					break;
				}
			}
		}
		cout<<sum<<" ";
	}
//	fclose(stdout);
	return 0;
}
