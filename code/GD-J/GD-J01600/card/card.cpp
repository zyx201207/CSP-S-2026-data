#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[1001010],b[1001010],c[1001010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i+1])p=1;
	}
	if(p==0){
		for(int i=1;i<=m;i++)cout<<1<<' ';
		return 0;
	}
	for(int i=n;i>=1;i--)if(b[a[i]]==0)b[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=0){
			if(b[a[j]]!=0){
				c[a[j]]++;
				j=b[a[j]]+1;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
