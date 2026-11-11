#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int p[500005],q[300005],idx=1;
		for(int j=i;j<=n;j++){
			if(q[a[j]]==0) q[a[j]]=1,p[idx]=a[j],idx++;
			else{
				while(p[idx]!=a[j]) idx--,p[idx]=0;
			}
			for(int i=1;i<=idx;i++) b[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
