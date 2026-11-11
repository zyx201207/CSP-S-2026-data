#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],b[100001],vis[300005],zb[300005],c[300005];
int main(){
	freopen("card.in ","r",stdin);
	freopen("card.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=0;
		memset(vis,0,sizeof vis);
		int j=n,t1=i;
		while(1){	
		    if(t1==n||(t1-1)==n) {b[++t]=a[t1];break;}	
			else if(a[j]==a[t1]) b[++t]=a[t1],t1=j+1,j=n;
			else if(j==t1) j=n,t1++;
			else j--;
		}
		for(int j=1;j<=t;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
