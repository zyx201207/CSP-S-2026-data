#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long mp[500002];
long long pp[500002];
long long a[522222];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		for(int j=n;j>0;j--){
			if(a[j]==i){
				pp[i]=j;
				break;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(pp[a[j]]!=0&&pp[a[j]]!=j){
				j=pp[a[j]];
			}
			mp[a[j]]++;
			if(j==n){
				break;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}

