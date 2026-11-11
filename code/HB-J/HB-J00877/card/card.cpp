#include<bits/stdc++.h>
using namespace std;
const int Q=5e3+5;
int nums[Q],len;
int lis[Q],jl[Q];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>lis[i];
	for(int i=1;i<=n;i++){
		len=0;
		for(int j=i;j<=n;j++){
			for(int k=len;k>=1;k--) if(lis[j]==nums[k]){len=k-1;break;}
			nums[++len]=lis[j];
		}
		for(int j=1;j<=len;j++) jl[nums[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<jl[i]<<" ";
	return 0;
}
