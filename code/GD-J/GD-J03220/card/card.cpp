#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int a[500005],d[300005],cnt[300005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==m)
			cout<<i<<" "; 
	}
	if(n==m)
		return 0;
	for(int i=1;i<=n;i++){
		int j=i,t=i;
		while(t<=n){
			if(!f[a[t]]){
				d[j]=a[t];
				f[a[t]]=1;
				j++; 
			}
			else{
				while(d[j]!=a[t]){
					f[d[j]]=0;
					j--;
				}
			}
			t++;
		}
		for(int i=1;i<=m;i++){
			if(f[i]){			
				cnt[i]++;
				f[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
