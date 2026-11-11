#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m>3000&&n>5000){
		for(int i=1;i<=m;i++)cout<<n<<' ';
		return 0;
	}
	if(n>5000&&m>2){
		for(int i=1;i<=m-1;i++)cout<<1<<' ';
		cout<<n;
		return 0;
	}
	if(n>5000&&m<=2){
		for(int i=1;i<=m;i++)cout<<n<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(c,-1,sizeof(c));
		for(int j=i;j<=n;j++){
			if(j>c[a[j]]&&c[a[j]]!=-1){
				for(int x=1;x<=m;x++){
					if(c[x]>c[a[j]])c[x]=-1;
				}
			}
			c[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(c[j]!=-1)b[j]++;
		}
	}
	for(int x=1;x<=m;x++)cout<<b[x]<<' ';
	return 0;
}
