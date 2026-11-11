#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5],b[m+5]={0},c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	int v=2,s=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==1){
			if(a[j]==a[v]){
				for(int e=j;e<=v;e++){
					a[e]=0;
				}
			}
			else{
				v++;
			}
			b[a[j]]++;
			}
			else{
				b[c[j]]++;
			}
			}
		}
	for(int i=1;i<=m;i++){
		if(i!=m){
			cout<<b[i]-1<<" ";
		}
		else{
			cout<<b[i]<<" ";
		}
	}
	return 0;
}