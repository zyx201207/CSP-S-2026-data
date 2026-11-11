#include<bits/stdc++.h>
using namespace std;
int n,e,a[500005],sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>e;
	const int M=e;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int m[M+5]={};
		for(int j=i;j<=n;j++){
			if(m[a[j]]!=0){
				for(int k=m[a[j]];k<=j;k++){
					m[a[k]]=0;
				}
			}
			m[a[j]]=j;
		}
		for(int j=1;j<=e;j++)
			if(m[j]!=0)
				sum[j]++;
	}
	for(int i=1;i<=e;i++)
		cout<<sum[i]<<' ';
	return 0;
}
