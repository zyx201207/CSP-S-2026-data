#include<bits/stdc++.h>
using namespace std;
int main(){
	freoprn("card.in","r",stdin);
	freoprn("card.out","w",stdout);
	long long n,m,a[500005],p[500005],ans=0,k[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		long long j=i;
		while(1){
			if(p[a[j]]!=j){
				j=p[a[j]];
			}else{
				k[a[j]]++;
				if(j==n)break;
				else j++;
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
} 
