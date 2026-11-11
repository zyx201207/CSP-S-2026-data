#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],d[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int b[10000]={0},c=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int k=1;k<=c;k++){
					b[k]=0;
				}
			}
			b[a[j]]++;
			c=max(c,a[j]);
		}
		for(int k=1;k<=c;k++)
			if(b[k])d[k]++;
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
}
