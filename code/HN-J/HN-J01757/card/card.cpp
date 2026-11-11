#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],t[500005];
bool c[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			a[j]=t[j];
		} 
		for(int j=i;j<=n;j++){
			if(c[a[j]]){
				//cout<<1234<<' ';
				for(int k=j;t[k]!=a[j]||k==j;k--){
					//cout<<1234567<<' ';
					b[a[k-1]]--;
					c[a[k-1]]=false;
					a[k-1]=0;
				}
			}
			b[a[j]]++;
			c[a[j]]=true;
			//cout<<a[j]<<b[a[j]]<<' ';
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
	
	
}
