#include<bits/stdc++.h>
using namespace std;
long long a[500100],sum[500100];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool b[500100];
		long long s[500100];
		for(int j=0;j<n;j++){
			s[j]=a[j+i];
			if(b[s[j]]==0){
				b[s[j]]=1;
			}
			else{
				s[j]=0;
				int z=1;
				while(s[j-z]!=a[j+i]){
					s[j-z]=0;
					z++;
				}
			}
		}
		for(int j=0;j<=m;j++){
			if(b[j]==1){
				sum[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

