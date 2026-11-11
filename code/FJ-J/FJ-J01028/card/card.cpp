#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>	
using namespace std;
int n,m,a[10005],b[10005],ans[10005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r=n-i+1;
		for(int j=1;j<=r;j++){
			b[j]=a[i-1+j];
		}
		bool c[10005]={},t[10005]={};
		for(int j=1;j<=r;j++){
			if(c[b[j]]==0){
				c[b[j]]=1;
				t[b[j]]++;
			}else{
				for(int k=1;k<=m;k++){
					
					c[k]=0;
					t[k]=0;
					//if(b[k]==b[j])break;
				}
				c[b[j]]=1;
				t[b[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=t[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
