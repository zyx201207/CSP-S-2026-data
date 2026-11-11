#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int q[500005];
int f=0;
void rusher(){
	int f[500005]={},cnt=0,c=1;
	while(q[c]){
		int u=q[c];
		for(int i=1;i<=cnt;i++){
			if(f[i]==u){
				for(int j=i;j<=cnt;j++)f[j]=0;
				cnt=i-1;
				break;
			}
		}
		cnt++;
		f[cnt]=u;
		c+=1;
	}
	for(int i=1;i<=cnt;i++){
		b[f[i]]+=1;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=i;j<=n;j++){
			f+=1;q[f]=a[j];
		}
		rusher();
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
}
