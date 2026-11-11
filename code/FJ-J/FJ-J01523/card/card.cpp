#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans[500005],table[500005];
void clear(long long k,long long x){
	for(int i=k;i<x;i++) table[i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		long long x=0;
		for(int j=s;j<n;j++){
			for(int k=0;k<x;k++){
				if(table[k]==a[j]){
					clear(k,x);
					x=0;
					break;
				}
			}
			table[x++]=a[j];
		}
		for(int j=0;j<x;j++) ans[table[i]]++;
		clear(0,x);
		s++;
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
	return 0;
}
