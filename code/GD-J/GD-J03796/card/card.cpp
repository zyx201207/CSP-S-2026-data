#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,a[N],b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			c[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]=1;
				b[a[j]]++;
			}
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
