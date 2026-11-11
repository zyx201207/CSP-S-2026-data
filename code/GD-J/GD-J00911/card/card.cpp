#include<bits/stdc++.h>
using namespace std;
int a[222222],f[222222],ff[222222];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],f[a[i]]++;
	ff[a[n]]=n;
	for(int i=n-1;i>=1;i++){
		if(i%2==1&&!ff[a[i]]){
			if(a[1]==a[i]&&f[a[i]]%2==0)ff[a[i]]=3;
			else if(f[a[i]]%2==1)ff[a[i]]=3;
			else ff[a[i]]=1;
		}
		else if(i%2==0&&!ff[a[i]]){
			if(a[1]==a[i]&&f[a[i]]%2==1)ff[a[i]]=3;
			else if(f[a[i]]%2==0)ff[a[i]]=3;
			else ff[a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ff[m]<<" ";
	} 
}
