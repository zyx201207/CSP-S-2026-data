#include<bits/stdc++.h>
using namespace std;
int Find[500010]={-1}, n,m,a[500010],hash[300010]={0},x;
int find(int i,int j){
	if(i==x){
		return 0;
	}
	if(Find[i]==-1){
		if(a[i]==j){
			return i;
		}
		
		Find[i]=find(i-1,j);
		return Find[i];
	}
	else{
		return Find[i];
	}
}
int main(){
	//GZ-J00101 贵阳市南明区李端棻中学 曾俊豪
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int k=1;k<=n;k++){
		x=k;
		for(int i=k;i<=n;i++){
			hash[a[i]]+=1;
			int f=find(i,a[i]);
			cout<<a[i];
			cout<<f<<endl;
			if(f>0){
				for(int j=f;j<i;j++){
					hash[a[j]]--;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<hash[i]<<' ';
	}
	return 0;
}
