#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a[500010],c[300010];
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		long long b[300010];
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0)b[a[j]]=1;
			else l=j;
		} 
		for(int x=l;x<=r;x++){
			c[x]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
