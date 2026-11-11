#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100001];
long long ans[100001];
long long l[100001];
void check(int i,int j,int n){
	for(int y=i;y<=j;y++){
		if(l[y]==n and l[y]!=0){
			for(int k=y;k<=n;k++){
				l[k]=0;
			}
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			l[j]=a[j];
			check(i,n,l[j]);
			ans[l[j]]++;
		}
		for(int j=1;j<=i-1;j++){
			l[j]=a[j];
			check(1,n,l[j]);
			ans[l[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
